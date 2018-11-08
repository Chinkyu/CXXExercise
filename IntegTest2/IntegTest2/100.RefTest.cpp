#include <iostream>
#include <string>

using namespace std;

// Once reference create and initialized, it can't be changed(address)
void ref_test() {
	int x = 3, y = 4;

	int& ref = x;
	cout << "ref = " << &ref << " " << ref << endl;

	ref = y;
	cout << "ref = " << &ref << " " << ref << endl;

	// error 
//	&ref = &y;
}

// reference to pointer 
void ref_test2() {
	int* intP;
	int*& ptrRef = intP;

	ptrRef = new int;
	*ptrRef = 5;

	cout << *ptrRef << " " << *intP << " : " << ptrRef << " " << intP << endl;
}

void main() {
	char c;

	cout << "reference testing" << endl;

	ref_test();
	ref_test2();

	cin >> c;
}
