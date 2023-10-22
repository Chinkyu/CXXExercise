// easy
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	bool makePalindrome(string s) {
		int l = s.size();

		int nmcount = 0;
		for (int i = 0, j = l - 1; i < l / 2; ++i, --j) {
			if (s[i] != s[j]) nmcount++;
		}

		if (nmcount <= 2) return true;
		return false;
	}
};

int main() {
	char c;

	Solution sol;

	string s = "abcdba";
	cout << sol.makePalindrome(s);

	cin >> c;

}