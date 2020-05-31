#include "stdafx.h"
#include "TextApp_Lib.h"


TextApp_Lib::TextApp_Lib()
{
}


TextApp_Lib::~TextApp_Lib()
{
}


double TextApp_Lib::Add(double a, double b) {
	return a + b;
}

string TextApp_Lib::SaySomething(string str) {
	return str;
}

string TextApp_Lib::Concatenate(string trg, string src) {
	return trg + src;
}

int TextApp_Lib::ConcatenateList(vector<string> strList, string &newStr) {
	string str = "";
	for (auto it : strList) {
		str += it;
	}
	newStr = str;
	cout << "newStr:" << newStr << endl;
	return strList.size();
}