#include "pch.h"
#include "../TextApp_Library/TextApp_Lib.h"


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}



TEST(TestCaseName2, TestName2) {
	TextApp_Lib testApp;

	EXPECT_EQ(11, testApp.Add(5, 5));
	//EXPECT_TRUE(true);
}