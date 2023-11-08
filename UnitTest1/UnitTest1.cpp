#include "pch.h"
#include "CppUnitTest.h"
#include "D:\project C++\lab 7.3_rek\lab 7.3_rek\lab 7.3_rek.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            int row = 3, col = 7;
            int** a = new int* [row]; {
                for (int i = 0; i < row; i++)
                    a[i] = new int[col];
            }
            int Low = -17;
            int High = 15;
            Create(a, row, col, Low, High);

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);
                }
            }

            for (int i = 0; i < row; i++) {
                delete[] a[i];
            }
            delete[] a;
        }
    };
}
