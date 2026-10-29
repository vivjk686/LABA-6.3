#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TESTING_IT
#include "../LABA-6.3.it/LABA-6.3.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63it
{
	TEST_CLASS(UnitTest63it)
	{
	public:
		
		TEST_METHOD(TestMin_StandardInt_FirstElementIsMin)
		{
			int a[] = { -15, 2, 10, -5, 0, 7 };
			int n = 6;
			int result = Min(a, n);
			Assert::AreEqual(-15, result);
		}

		TEST_METHOD(TestMin_StandardInt_LastElementIsMin)
		{
			int a[] = { 10, 20, 5, 8, -42 };
			int n = 5;
			int result = Min(a, n);
			Assert::AreEqual(-42, result);
		}

		TEST_METHOD(TestMin_StandardInt_MiddleElementIsMin)
		{
			int a[] = { 4, 12, -99, 50, 3 };
			int n = 5;
			int result = Min(a, n);
			Assert::AreEqual(-99, result);
		}

		TEST_METHOD(TestMin_TemplateInt)
		{
			int a[] = { 100, 25, 3, 44, 12 };
			int n = 5;
			int result = Min<int>(a, n);
			Assert::AreEqual(3, result);
		}

		TEST_METHOD(TestMin_TemplateDouble)
		{
			double b[] = { 5.25, -3.14, 0.0, -10.5, 7.8 };
			int n = 5;
			double result = Min<double>(b, n);
			Assert::AreEqual(-10.5, result, 1e-9);
		}

		TEST_METHOD(TestMin_SingleElement)
		{
			int a[] = { 42 };
			int result = Min(a, 1);
			Assert::AreEqual(42, result);
		}

		TEST_METHOD(TestMin_AllNegativeNumbers)
		{
			int a[] = { -10, -2, -50, -4, -1 };
			int n = 5;
			int result = Min(a, n);
			Assert::AreEqual(-50, result);
		}

		TEST_METHOD(TestMin_DuplicateMinimums)
		{
			int a[] = { 5, -8, 2, -8, 10, -8 };
			int n = 6;
			int result = Min(a, n);
			Assert::AreEqual(-8, result);
		}
	};
}
