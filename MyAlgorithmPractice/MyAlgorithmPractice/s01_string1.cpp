#include <iostream>
#include <string>

using namespace std;

void string_test() {
	string s1 = "String test";

	for (string::iterator it = s1.begin(); it < s1.end(); ++it) {
		cout << " " << *it;
	}


}


int main() {
	char c;

	string_test();

	cin >> c;
}