#include <iostream>

using namespace std;


class Solution {
public:
	string intToRoman(int num) {
		string str = "";

		while (num > 0) {
			if (num >= 1000) {
				str.append("M"); num -= 1000; continue;
			}
			else if (num >= 900) {
				str.append("CM"); num -= 900; continue;
			}
			else if (num >= 500) {
				str.append("D"); num -= 500; continue;
			}
			else if (num >= 400) {
				str.append("CD"); num -= 400; continue;
			}
			else if (num >= 100) {
				str.append("C"); num -= 100; continue;
			}
			else if (num >= 90) {
				str.append("XC"); num -= 90; continue;
			}
			else if (num >= 50) {
				str.append("L"); num -= 50; continue;
			}
			else if (num >= 40) {
				str.append("XL"); num -= 40; continue;
			}
			else if (num >= 10) {
				str.append("X"); num -= 10; continue;
			}
			else if (num >= 9) {
				str.append("IX"); num -= 9; continue;
			}
			else if (num >= 5) {
				str.append("V"); num -= 5; continue;
			}
			else if (num >= 4) {
				str.append("IV"); num -= 4; continue;
			}
			else {
				str.append("I"); num -= 1; continue;
			}
		}
		return str;
	}
};


int main() {
	char c;
	int num;
	Solution sol;


	while (true) {
		cin >> num;
		cout << sol.intToRoman(num).c_str() << endl;
	}
	cin >> c;
}
