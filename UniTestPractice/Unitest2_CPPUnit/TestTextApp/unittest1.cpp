#include "stdafx.h"
#include "CppUnitTest.h"
#include "TextApp_Lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestTextApp
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TextApp_Lib *textApp;

		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			Assert::AreEqual(true, true);
		}

		TEST_METHOD(TestMethod2)
		{
			//TextApp_Lib textApp;
			// TODO: Your test code here
			Assert::AreEqual(11.0, textApp->Add(5.5, 5.5));
		}

	};
}