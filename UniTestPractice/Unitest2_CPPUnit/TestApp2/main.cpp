#include <iostream>
#include "../TextApp_Library/TextApp_Lib.h"

using namespace std;

int main() {

	TextApp_Lib *obj = new TextApp_Lib();
	string str = obj->SaySomething("Hello world");
	cout << "str:" << str << endl;
	system("pause");
}