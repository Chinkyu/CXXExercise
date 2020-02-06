#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		string ans = "";                                         // treat ans as a stack in below for loop

		for (char c : num) {
			while (ans.length() && ans.back() > c && k) {
				ans.pop_back();                                  // make sure digits in ans are in ascending order
				k--;                                             // remove one char
			}

			if (ans.length() || c != '0') { ans.push_back(c); }  // can't have leading '0'
		}

		while (ans.length() && k--) { ans.pop_back(); }          // make sure remove k digits in total

		return ans.empty() ? "0" : ans;
	}
};

int main() {
	char c;
	string num = "1432219";
	Solution sol;

	cout << sol.removeKdigits(num, 3).c_str();

	cin >> c;
}