// easy
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
	int waysToSplitArray(vector<int>& nums) {
		int ans = 0;
		int l = nums.size();
		long long lsum = nums[0];
		long long rsum = 0;
		for (int i = 1; i < l; ++i) rsum += nums[i];

		if (lsum >= rsum) ans++;


		for (int i = 1; i < l - 1; ++i) {
			lsum += nums[i];
			rsum -= nums[i];
			if (lsum >= rsum) ans++;
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 10,4,-8,7 };
	cout << sol.waysToSplitArray(nums);

	cin >> c;

}