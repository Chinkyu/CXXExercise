//   ¥‰îf¿Ω.. dp, monotonic stack ??  
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

// See anser
class Solution {
	long long minCost(vector<int>& nums, vector<int>& costs) {
		int n = nums.size();
		stack<int> ss;
		stack<int> sb;
		vector<long long> dp(n, LONG_LONG_MAX);
		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			while (!ss.empty() && nums[i] < nums[ss.top()]) {
				dp[i] = min(dp[i], dp[ss.top()] + costs[i]);
				ss.pop();
			}
			ss.push(i);
			while (!sb.empty() && nums[i] >= nums[sb.top()]) {
				dp[i] = min(dp[i], dp[sb.top()] + costs[i]);
				sb.pop();
			}
			sb.push(i);
		}
		return dp[n - 1];
	}
};



// timeout 
class _Solution {
public:
	vector<long long> min_map;
	long long minTraverse(vector<int> & nums, vector<int> & costs, int idx) {
		int l = nums.size();
		long long minCost = LLONG_MAX;
		if (idx == l - 1) {
			return 0; LLONG_MAX; //  costs[idx];
		}
		if (min_map[idx] != LLONG_MAX) return min_map[idx];

		//int tmax = nums[idx], tmin = nums[idx];
		int tmax = -1, tmin = INT_MAX;
		for (int j = idx + 1; j < l; ++j) {
			long long cost = LLONG_MAX;
			if (nums[idx] <= nums[j]) {
				if (tmax < nums[idx]) {
					// jump
					cost = costs[j];
					cost += minTraverse(nums, costs, j);
				}
				else {
					
				}
			}
			else {
				if (nums[idx] <= tmin) {
					// jump
					cost = costs[j];
					cost += minTraverse(nums, costs, j);
				}
				else {

				}
			}

			tmax = max(tmax, nums[j]);
			tmin = min(tmin, nums[j]);

			minCost = min(minCost, cost);
		}

		min_map[idx] = minCost;
		return minCost;
	}

	long long minCost(vector<int>& nums, vector<int>& costs) {
		int l = nums.size();
		min_map = vector<long long>(l, LLONG_MAX);
		return minTraverse(nums, costs, 0);
	}
};

int main() {
	char c;

	Solution sol;

	//vector<int> nums = { 3,2,4,4,1 };
	//vector<int> costs = { 3,7,6,4,2 };
	//cout << sol.minCost(nums, costs);

	vector<int> nums = { 0, 1, 2 };
	vector<int> costs = { 1, 1, 1 };
	cout << sol.minCost(nums, costs);

	cin >> c;

}