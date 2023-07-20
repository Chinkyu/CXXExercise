// 답 봤음..  좀 이해가 잘 안감...  
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
	bool isReachEnd = false;
	int maxJumps = 0;
	int traverse(vector<int>& nums, int target, int idx, int jumps, vector<int> &dp) {
		int n = nums.size();
		if (idx == n - 1) { return 0; }
		if (dp[idx] != INT_MIN) return dp[idx];

		int res = -1;
		for (int i = idx + 1; i < n; ++i) {
			if (abs(nums[idx] - nums[i]) <= target) {
				int t = traverse(nums, target, i, jumps + 1, dp);
				if (t != -1) res = max(res, t + 1);
			}
		}

		return dp[idx] = res;
	}


	int maximumJumps(vector<int>& nums, int target) {
		vector<int> dp(nums.size(), INT_MIN);
		int ans = traverse(nums, target, 0, 0, dp);

		return ans;
	}
};


// timeout 
class _Solution {
public:
	bool isReachEnd = false;
	int maxJumps = 0;
	void traverse(vector<int>& nums, int target, int idx, int jumps) {
		int n = nums.size();
		if (idx == n - 1) {
			isReachEnd = true;
			maxJumps = max(maxJumps, jumps);
			return;
		}

		for (int i = idx + 1; i < n; ++i) {
			if (abs(nums[idx] - nums[i]) <= target) {
				traverse(nums, target, i, jumps + 1);
			}
		}
	}


	int maximumJumps(vector<int>& nums, int target) {
		isReachEnd = false;
		maxJumps = 0;
		traverse(nums, target, 0, 0);

		if (isReachEnd == false) return -1;
		return maxJumps;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 1151004,-368271873,-959137308,-363298760,860913529,875734893,653205161,-726919163,-107413863,-142574923,535616977,-527647589,-933518315,622674836,-626420393,718010621,443503514,324638485,303398068,404393712,-682845482,957378126,254180033,527664388,204099822,59043697,284163204,-18806397,54466771,218940186,122932328,-527134788,748489009,481143527,-91930114,650935932,49918996,838929409,298033606,135544915,-231923297,-564040431,-403686128,-779212295 };
	cout << sol.maximumJumps(nums, 1152175137);

	cin >> c;
}
