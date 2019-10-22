#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string add(string num1, string num2) {
		int s1 = num1.size() - 1;
		int s2 = num2.size() - 1;
		int len = (s1 > s2) ? s1 : s2;
		string ans;

		int carry = 0;
		int sum;
		do {
			if (s1 >= 0 && s2 >= 0) sum = num1[s1] + num2[s2] + carry - '0';
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

	bool isAdditiveNumber(string num) {
		for (int i = 1; i <= num.size() / 2; i++) {
			for (int j = 1; j <= (num.size() - i) / 2; j++) {
				if (check(num.substr(0, i), num.substr(i, j), num.substr(i + j))) return true;
			}
		}
		return false;
	}
	bool check(string num1, string num2, string num) {
		if (num1.size() > 1 && num1[0] == '0' || num2.size() > 1 && num2[0] == '0') return false;
		string sum = add(num1, num2);
		if (num == sum) return true;
		if (num.size() <= sum.size() || sum.compare(num.substr(0, sum.size())) != 0) return false;
		else return check(num2, sum, num.substr(sum.size()));
	}
};

int main() {
	char c;
	string s = "112358";
	Solution sol;

	cout << sol.isAdditiveNumber(s);
	cin >> c;
}
