#include <iostream>
#include <string>

using namespace std;


void StringTest1() {
//	float f1 = 3.14;
//	string s1 = to_string(f1);

//	cout << s1 << endl;
}

void stringTest2() {
	string s2;

	s2.resize(3);
	s2[2] = '1';

	cout << s2 << endl;

	s2.resize(2);
	cout << s2 << endl;

	s2.resize(10);
	cout << s2 << endl;
}


int main() {
	int i;

//	StringTest1();
	stringTest2();

	cin >> i ;

}