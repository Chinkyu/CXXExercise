//  easy
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
	int minimumDeletions(vector<int>& nums) {
		int l = nums.size();

		int tmin = INT_MAX, tminIdx = -1;
		int tmax = INT_MIN, tmaxIdx = -1;

		if (l == 1) return 1;

		for (int i = 0; i < l; ++i) {
			if (tmin >= nums[i]) {
				tmin = nums[i];
				tminIdx = i;
			}

			if (tmax <= nums[i]) {
				tmax = nums[i];
				tmaxIdx = i;
			}
		}

		int ans = l - (abs(tmaxIdx - tminIdx) - 1);  // out side

		if (tminIdx <= tmaxIdx) {
			// remove left
			ans = min(ans, tmaxIdx + 1);
			// remove right
			ans = min(ans, l - tminIdx);
		}
		else {
			// remove left
			ans = min(ans, tminIdx + 1);
			// remove right
			ans = min(ans, l - tmaxIdx);
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { -87,60,-30,-67,74,55,76,-53 };// { 2, 10, 7, 5, 4, 1, 8, 6 };

	cout << sol.minimumDeletions(nums);


	cin >> c;
}