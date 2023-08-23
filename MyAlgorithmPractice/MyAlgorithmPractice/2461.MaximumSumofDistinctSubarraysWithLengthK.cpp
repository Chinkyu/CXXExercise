//  count variable 로  sliding window 방식으로 하면 됨.
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
	bool isAllOne(unordered_map<int, int> & oneMoreC) {
		if (oneMoreC.size() > 0) return false;
		return true;
	}

	long long maximumSubarraySum(vector<int>& nums, int k) {
		long long sum = 0, max_sum = 0;
		//vector<int> c(10, 0);
		unordered_map<int, int> c, oneMoreC;
		int l = nums.size();

		if (l < k) return 0;

		for (int i = 0; i < k; ++i) {
			c[nums[i]]++;
			if (c[nums[i]] > 1) oneMoreC[nums[i]] = 1;

			sum += nums[i];
		}
		if (isAllOne(oneMoreC)) max_sum = max(sum, max_sum);

		for (int i = k; i < l; ++i) {
			c[nums[i - k]]--;
			if (c[nums[i - k]] <= 1 && oneMoreC.find(nums[i - k]) != oneMoreC.end()) { oneMoreC.erase(nums[i - k]); }
			sum -= nums[i - k];
			
			c[nums[i]]++;
			if (c[nums[i]] > 1) oneMoreC[nums[i]] = 1;
			sum += nums[i];

			if (isAllOne(oneMoreC)) max_sum = max(sum, max_sum);
		}

		return max_sum;

	}
};

int main() {
	char c;

	Solution sol;
	vector<int> nums = { 14,2,11,19,6,18,8,20,11 }; // { 1, 5, 4, 2, 9, 9, 9 };
	//vector<int> nums = { 1, 5, 4, 2, 9, 9, 9 };

	cout << sol.maximumSubarraySum(nums, 6);
	cin >> c;
}