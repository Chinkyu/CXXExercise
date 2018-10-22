#include <iostream>

using namespace std;

void func1(char * str) {
	cout << "func with char* str  : str == " << str << endl;
}

void func1(int i) {
	cout << "func with int : int == " << i << endl;
}

int main() {
	char c;
    func1(NULL);
	func1(nullptr);
	cin >> c;
}