//  ¥‰∫√¿Ω....  dp ?? 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
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
	int n, INF = 200 * 1e6;
	int memo[200][200] = {};
	int minSpaceWastedKResizing(vector<int> &nums, int k) {
		memset(memo, -1, sizeof(memo));
		n = nums.size();
		return dp(nums, 0, k);
	}
	int dp(vector<int> &nums, int i, int k) {
		if (i == n) return 0;
		if (k == -1) return INF;
		if (memo[i][k] != -1) return memo[i][k];
		int ans = INF, maxNum = nums[i], totalSum = 0;
		for (int j = i; j < n; ++j) {
			maxNum = max(maxNum, nums[j]);
			totalSum += nums[j];
			int wasted = maxNum * (j - i + 1) - totalSum;
			ans = min(ans, dp(nums, j + 1, k - 1) + wasted);
		}
		return memo[i][k] = ans;
	}
};
int main() {
	char c;
	Solution sol;

	vector<int> piles = { 4, 3, 6, 7 };

	cout << sol.minStoneSum(piles, 3);

	cin >> c;
}