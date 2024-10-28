#include <iostream>
#include <iomanip>
using namespace std;

void generateMatrix(int** matrix, int rows, int cols, int min, int max) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (rand() % (max - min + 1)) + min;
        }
    }
}

void calculateAndReplace(int** matrix, int rows, int cols, int& count, int& sum) {
    count = 0;
    sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > 0 && (i % 3 != 0) && (j % 3 != 0)) {
                count++;
                sum += matrix[i][j];
                matrix[i][j] = 0;
            }
        }
    }
}

void sortColumns(int** matrix, int rows, int cols) {
    int* indices = new int[cols];
    for (int i = 0; i < cols; i++) {
        indices[i] = i;
    }

    for (int i = 0; i < cols - 1; i++) {
        for (int j = 0; j < cols - i - 1; j++) {
            if (matrix[0][indices[j]] > matrix[0][indices[j + 1]]) {
                swap(indices[j], indices[j + 1]);
            }
            else if (matrix[0][indices[j]] == matrix[0][indices[j + 1]]) {
                if (matrix[1][indices[j]] > matrix[1][indices[j + 1]]) {
                    swap(indices[j], indices[j + 1]);
                }
                else if (matrix[1][indices[j]] == matrix[1][indices[j + 1]]) {
                    if (matrix[2][indices[j]] < matrix[2][indices[j + 1]]) {
                        swap(indices[j], indices[j + 1]);
                    }
                }
            }
        }
    }

    int** sortedMatrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        sortedMatrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            sortedMatrix[i][j] = matrix[i][indices[j]];
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
        matrix[i] = sortedMatrix[i];
    }
    delete[] sortedMatrix;
    delete[] indices;
}

void printMatrix(int** matrix, int rows, int cols) {
    cout << fixed << setprecision(2);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    const int rows = 7;
    const int cols = 5;
    const int min = -6;
    const int max = 31;
    int count = 0, sum = 0;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    generateMatrix(matrix, rows, cols, min, max);
    cout << "Original Matrix:\n";
    printMatrix(matrix, rows, cols);

    calculateAndReplace(matrix, rows, cols, count, sum);
    cout << "\nModified Matrix:\n";
    printMatrix(matrix, rows, cols);
    cout << "Count of positive elements: " << count << endl;
    cout << "Sum of positive elements: " << sum << endl;

    sortColumns(matrix, rows, cols);

    cout << "\nSorted Matrix:\n";
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
