#include <iostream>
#include <string>
#include <vector>

using namespace std;

// rvalue reference exam


// Increment value using lvalue reference parameter
int incr(int& value) {

	cout << "increment with lvalue reference" << endl;
	++value;
	return value;
}

// Incremant value using rvalue reference parameter
int incr(int&& value) {

	cout << "increment with rvalue reference" << endl;
	++value;
	return value;
}


void rvalref_test() {
	int a = 10, b = 20;

	cout << incr(a) << endl;

	cout << incr(a + b) << endl;

	cout << incr(3) << endl;

	cout << 3 << endl;
}


void main() {
	char c;

	cout << "rvalue reference testing" << endl;

	rvalref_test();

	cin >> c;
}
