#include <iostream>

using namespace std;


class Solution {
public:
    string intToRoman(int num) {
  
	  while(num <= 0) {
		if (num >= 1000) {
			cout << "M";num -= 1000;continue;
		} else if (num >= 900) {
			cout << "CM";num -= 900;continue;
		} else if (num >= 500) {
			cout << "D";num -= 500;continue;
		} else if (num >= 400) {
			cout << "CD";num -= 400;continue;
		} else if (num >= 100) {
			cout << "L";num -= 100;continue;
		} else if (num >= 90) {
			cout << "XC";num -= 90;continue;
		} else if (num >= 50) {
			cout << "L";num -= 50;continue;
		} else if (num >= 40) {
			cout << "XL";num -= 40;continue;
		} else if (num >= 10) {
			cout << "X";num -= 10;continue;
		} else if (num >= 9) {
			cout << "IX";num -= 9;continue;
		} else if (num >= 5) {
			cout << "V";num -= 5;continue;
		} else if (num >= 4) {
			cout << "IV";num -= 4;continue;
		} else {
			cout << "I";num -= 1;continue;
		}
	  }
    }
};


int main() {
	char c;
	int num;
	Solution sol;


	while (true) {
		cin >> num;
		sol.intToRoman(num);
	}
	cin >> c;
}
