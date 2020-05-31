#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Unitest1/Function1.h"

extern bool isLargeThan10(int x);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CppUnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			Solution1 sol;
			//bool b = sol.isLarge(12);
			//bool b = isLargeThan10(12);

			//Assert::IsTrue(sol.isLarge(12));
		}

	};
}