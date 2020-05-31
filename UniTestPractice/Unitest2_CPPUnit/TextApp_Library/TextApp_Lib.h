#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class TextApp_Lib
{
public:
	TextApp_Lib();
	~TextApp_Lib();
	double Add(double a, double b);
	string SaySomething(string str);
	string Concatenate(string tgt, string src);
	int ConcatenateList(vector<string> strList, string &newStr);
};

