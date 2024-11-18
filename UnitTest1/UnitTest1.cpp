#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.2_rec/7.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int rows = 3;
            const int cols = 3;
            const int Low = -9;
            const int High = 9;

            int** matrix = new int* [rows];
            for (int i = 0; i < rows; i++)
                matrix[i] = new int[cols];

            CreateRows(matrix, rows, cols, Low, High, 0);

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    Assert::IsTrue(matrix[i][j] >= Low && matrix[i][j] <= High);
                }
            }

            for (int i = 0; i < rows; i++)
                delete[] matrix[i];
            delete[] matrix;
        };
    };
}
