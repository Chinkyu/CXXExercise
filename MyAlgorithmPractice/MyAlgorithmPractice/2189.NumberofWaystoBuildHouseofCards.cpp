//´äºÃÀ½ :  dp  ·Î Ç¬´Ù´Âµ¥...
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>
#include <cmath>

using namespace std;

class Solution {
	int ret = 0;
	int dfs(int n, int k, vector<vector<int>>&dp) {
		if (n < 0 || k < 0)
			return  0;
		if (dp[k][n] != -1)
			return dp[k][n];

		if (n > 0 && k == 0) {
			dp[k][n] = 0;
			return 0;
		}

		if (n == 0) {
			dp[k][n] = 1;
			return 1;
		}

		int ret = 0;
		for (int i = k; i >= 0; i--) {
			int use = 2 * i + i - 1;
			if ((n - use) < 0)
				continue;
			ret += dfs(n - use, i - 1, dp);
		}
		dp[k][n] = ret;
		return ret;
	}
public:
	int houseOfCards(int n) {
		if (n == 2)
			return 1;
		int k = n / 2;
		vector<vector<int>>dp(k + 1, vector<int>(n + 1, -1));
		dp[0][0] = 1;
		dfs(n, k, dp);
		return dp[k][n];
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> mapping = { 8,9,4,0,2,1,3,5,7,6 };
	vector<int> nums = { 991,338,38 };

	vector<int> ans = sol.sortJumbled(mapping, nums);

	for (auto &it : ans) {
		cout << it << " ";
	}

	cin >> c;

}