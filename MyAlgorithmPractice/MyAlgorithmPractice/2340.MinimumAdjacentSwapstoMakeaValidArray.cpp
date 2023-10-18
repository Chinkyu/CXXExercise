// easy : cross  --> -1
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
	int minimumSwaps(vector<int>& nums) {
		int l = nums.size();
		int ans = 0;

		int mini = -1, maxi = -1;
		int minv = INT_MAX, maxv = -1;

		if (l == 1) return 0;

		for (int i = 0; i < l; ++i) {
			if (nums[i] < minv) { // min left asap
				minv = nums[i];
				mini = i;
			}
			if (maxv <= nums[i]) {  // max right asap
				maxv = nums[i];
				maxi = i;
			}
		}

		ans = mini + (l - maxi - 1);
		if (maxi < mini) {
			ans--;
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 3, 4, 5, 5, 3, 1 };

	cout << sol.minimumSwaps(nums);

	cin >> c;

}