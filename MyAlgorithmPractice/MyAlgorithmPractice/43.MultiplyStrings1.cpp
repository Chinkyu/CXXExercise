#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

	string add(string num1, string num2) {
		int s1 = num1.size()-1;
		int s2 = num2.size()-1;
		int len = (s1 > s2) ? s1 : s2;
		string ans;

		int carry = 0;
		int sum;
		do {
			if(s1 >= 0 && s2 >= 0) sum = num1[s1] + num2[s2] + carry - '0';
			else if (s1 >= 0 && s2 < 0) sum = num1[s1] + carry;
			else sum = num2[s2] + carry;
			if (sum > '9') {
				carry = 1;
				sum -= 10;
			}
			else {
				carry = 0;
			}
			ans.push_back(sum);

			if (s1 >= 0) s1--;
			if (s2 >= 0) s2--;

		} while (s1 >= 0 || s2 >= 0);

		if (carry >= 1) ans.push_back('1');

		reverse(ans.begin(), ans.end());
		return ans;
	}

	string oneDigitMultiply(string num1, int c) {
		int s1 = num1.size() - 1;
		string ans;

		if (c == 0) return "0";

		int carry = 0;
		for (int i = s1; i >= 0; --i) {
			int d = (num1[i] - '0') * c + carry;
			if (d > 9) {
				carry = d / 10;
				ans.push_back(d % 10 + '0');
			}
			else {
				carry = 0;
				ans.push_back(d + '0');
			}
		}
		if (carry > 0) ans.push_back(carry + '0');

		reverse(ans.begin(), ans.end());
		return ans;
	}

	string multiply(string num1, string num2) {
		int s1 = num1.size();
		int s2 = num2.size();
		string ans;

		string l, s;

		if (s1 > s2) {
			l = num1; s = num2;
		}
		else {
			l = num2; s = num1;
		}

		//ans = l;
		for (int i = s.size() - 1; i >= 0; --i) {
			string temp = oneDigitMultiply(l, s[i]-'0');
			for (int j = 0; s.size()- 1 - i > j; ++j) {
				temp.push_back('0');
			}
			ans = add(ans, temp);
		}

		return ans;
	}
};


int main() {
	Solution sol;
	char c;
	string n1 = "9999"; // "123";// = "22222";
	string n2 = "9"; // "456";


//	cout << sol.add(n1, n2).c_str();
	cout << sol.oneDigitMultiply(n1, 0).c_str();
//	cout << sol.multiply(n1, n2).c_str();


	cin >> c;
}