#include <iostream>
#include <string>

using namespace std;

bool checkPalindrom1(string str, int st, int ed) {
	int i, j;

	i = st;
	j = ed;

	while (i < j) {
		if (str[i++] != str[j--]) return false;
	}
	return true;
}


int main() {
	int i;
	string s = "abcba";
	cout << "palindrom test" << endl;

	cout << checkPalindrom1(s, 0, s.length()-1);
	cin >> i;
}