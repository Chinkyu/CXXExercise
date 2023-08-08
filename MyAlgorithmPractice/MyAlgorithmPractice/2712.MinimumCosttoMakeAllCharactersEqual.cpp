// 답봤음...참 어이 없군... !!
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
#include <cmath>

using namespace std;

class Solution {
public:
	long long minimumCost(string s) {
		int n = s.length();
		long long ans = 0;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] != s[i + 1]) ans += min(i + 1, n - i - 1);
		}
		return ans;
	}
};
int main() {
	char c;

	Solution sol;

	string s = "0010";// "5494"; // "52233";
	cout << sol.longestSemiRepetitiveSubstring(s);
	//cout << sol.longestString(3, 25, 48);

	cin >> c;
}
