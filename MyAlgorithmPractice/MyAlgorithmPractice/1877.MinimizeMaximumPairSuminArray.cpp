// 문제가 이해 안되서 답봤음.. 

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
	int minPairSum(vector<int>& nums) {
		int l = nums.size();
		sort(nums.begin(), nums.end());

		int ans = 0;
		for (int i = 0; i < l / 2; ++i) {
			ans = max(ans, nums[i] + nums[l - 1 - i]);
		}
		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> nums = { 3,5,4,2,4,6 };
	cout << sol.minPairSum(nums);
	cin >> c;
}