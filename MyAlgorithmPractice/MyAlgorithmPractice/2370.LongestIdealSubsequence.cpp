// ¥‰∫√¿Ω   DP
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

// dp
class Solution {
public:
	int longestIdealString(string s, int k) {
		int dp[150] = {}, res = 0;
		for (auto& i : s) {
			for (int j = i - k; j <= i + k; ++j)
				dp[i] = max(dp[i], dp[j]);
			res = max(res, ++dp[i]);
		}
		return res;
	}
};



class _Solution {
public:

	// recursive??

	int _traverse(string s, int k, int idx, string made) {
		int l = s.size();
		if (idx >= l) return size(made);

		
		// not select
		int lm = traverse(s, k, idx + 1, made);
		// select
		// check distance
		int rm = 0;
		if (made.size() > 0) {
			char c1 = made[made.size() - 1];
			char c2 = s[idx];

			if (abs(c1 - c2) <= k) {
				made.push_back(c2);
				rm = traverse(s, k, idx + 1, made);
			}
		}
		else {
			made.push_back(s[idx]);
			rm = traverse(s, k, idx + 1, made);
		}

		return max(lm, rm);
	}

	map<string, int> m;


	int traverse(string s, int k, int idx, string made) {
		int l = s.size();
		if (idx >= l) return size(made);

		if (m.find(made) != m.end()) return m[made];


		// not select
		int lm = traverse(s, k, idx + 1, made);
		// select
		// check distance
		int rm = 0;
		if (made.size() > 0) {
			char c1 = made[made.size() - 1];
			char c2 = s[idx];

			if (abs(c1 - c2) <= k) {
				made.push_back(c2);
				rm = traverse(s, k, idx + 1, made);
			}
		}
		else {
			made.push_back(s[idx]);
			rm = traverse(s, k, idx + 1, made);
		}


		m[made] = max(m[made], max(lm, rm));
		return max(lm, rm);
	}

	int longestIdealString(string s, int k) {
		string made;
		return traverse(s, k, 0, made);
	}
};

int main() {
	char c;

	Solution sol;
	string str = "slddedwfmo"; // "acfgbd";

	cout << sol.longestIdealString(str, 16);

	cin >> c;

}