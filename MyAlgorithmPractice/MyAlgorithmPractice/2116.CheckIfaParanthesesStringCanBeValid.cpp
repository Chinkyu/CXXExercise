// 그냥 카피 

/*
A useful trick (when doing any parentheses validation) is to greedily check balance left-to-right, and then right-to-left.

	Left-to-right check ensures that we do not have orphan ')' parentheses.
	Right-to-left checks for orphan '(' parentheses.

We go left-to-right:

	Count wild (not locked) characters.
	Track the balance bal for locked parentheses.
		If the balance goes negative, we check if we have enough wild characters to compensate.
	In the end, check that we have enough wild characters to cover positive balance (open parentheses).

This approach alone, however, will fail for ["))((", "0011"] test case. That is why we also need to do the same going right-to-left.

*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	bool canBeValid(string s, string locked) {
		auto validate = [&](char op) {
			int bal = 0, wild = 0, sz = s.size();
			int start = op == '(' ? 0 : sz - 1, dir = op == '(' ? 1 : -1;
			for (int i = start; i >= 0 && i < sz && wild + bal >= 0; i += dir)
				if (locked[i] == '1')
					bal += s[i] == op ? 1 : -1;
				else
					++wild;
			return abs(bal) <= wild;
		};
		return s.size() % 2 == 0 && validate('(') && validate(')');
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> arr = { 2,1,3,1,2,3,3 };

	vector<long long> ans = sol.getDistances(arr);

	for (auto &it : ans) {
		cout << it << " ";
	}

	cin >> c;
}