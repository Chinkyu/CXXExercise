//  easy
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

using namespace std;

class Solution {
public:
	long long maximumSumScore(vector<int>& nums) {
		int l = nums.size();

		long long lsum = 0, rsum = 0;
		for (int i = 0; i < l; ++i) rsum += nums[i];

		long long ans = rsum;
		for (int i = 1; i < l; ++i) {
			lsum += nums[i-1];
			rsum -= nums[i-1];
			ans = max(ans, lsum);
			ans = max(ans, rsum);
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { -6, 0, -2, -3 }; // { -3, -5 }; // { 4, 3, -2, 5 };
	cout << sol.maximumSumScore(nums);

	cin >> c;

}