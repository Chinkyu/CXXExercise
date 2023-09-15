//  easy... 
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
	int longestContinuousSubstring(string s) {
		int sti = 0, ci = 0;
		int l = s.size();

		int maxl = 0;
		for (int i = 1; i < l; ++i) {
			if (s[i] == s[i - 1] + 1) {
				continue;
			}
			else {
				maxl = max(maxl, i - sti);
				sti = i;
			}
		}

		maxl = max(maxl, l - sti);
		return maxl;
	}
};

int main() {
	char c;

	Solution sol;
	string s = "abacaba";
	cout << sol.longestContinuousSubstring(s);

	cin >> c;
}