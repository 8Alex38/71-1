#include "pch.h"
#include "CppUnitTest.h"
#include "../71-1/71-1.cpp"  
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MatrixUnitTests
{
    TEST_CLASS(MatrixTests)
    {
    public:

        TEST_METHOD(TestGenerateMatrix)
        {
            const int rows = 7;
            const int cols = 5;
            int min = -6;
            int max = 31;

            int** matrix = new int* [rows];
            for (int i = 0; i < rows; i++) {
                matrix[i] = new int[cols];
            }

            generateMatrix(matrix, rows, cols, min, max);

            bool withinRange = true;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (matrix[i][j] < min || matrix[i][j] > max) {
                        withinRange = false;
                        break;
                    }
                }
            }

            Assert::IsTrue(withinRange);

            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        TEST_METHOD(TestCalculateAndReplace)
        {
            const int rows = 3;
            const int cols = 3;
            int count = 0;
            int sum = 0;

            int** matrix = new int* [rows];
            for (int i = 0; i < rows; i++) {
                matrix[i] = new int[cols];
            }

            int sampleMatrix[3][3] = {
                {1,  2,  3},    
                {4,  5,  6},   
                {7, -8,  9}    
            };

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    matrix[i][j] = sampleMatrix[i][j];
                }
            }

            calculateAndReplace(matrix, rows, cols, count, sum);

            int expectedCount = 3;     
            int expectedSum = 20;       

            Assert::AreEqual(expectedCount, count, L"Count does not match the expected value.");
            Assert::AreEqual(expectedSum, sum, L"Sum does not match the expected value.");

            Assert::AreEqual(0, matrix[1][1]); 
            Assert::AreEqual(0, matrix[1][2]);
            Assert::AreEqual(0, matrix[2][2]); 

            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        TEST_METHOD(TestSortColumns)
        {
            const int rows = 3;
            const int cols = 3;
            int** matrix = new int* [rows];
            for (int i = 0; i < rows; i++) {
                matrix[i] = new int[cols];
            }

            int sampleMatrix[3][3] = {
                {3, 1, 2},
                {9, 5, 6},
                {7, 8, 4}
            };

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    matrix[i][j] = sampleMatrix[i][j];
                }
            }

            sortColumns(matrix, rows, cols);

            Assert::AreEqual(1, matrix[0][0]);
            Assert::AreEqual(2, matrix[0][1]);
            Assert::AreEqual(3, matrix[0][2]);
            Assert::AreEqual(5, matrix[1][0]);
            Assert::AreEqual(6, matrix[1][1]);
            Assert::AreEqual(9, matrix[1][2]);
            Assert::AreEqual(8, matrix[2][0]);
            Assert::AreEqual(4, matrix[2][1]);
            Assert::AreEqual(7, matrix[2][2]);

            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    };
}
