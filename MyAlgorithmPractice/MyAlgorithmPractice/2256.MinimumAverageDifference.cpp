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
	int minimumAverageDifference(vector<int>& nums) {
		long long left = 0, right = 0;
		int lavg = 0, ravg = 0;
		int l = nums.size();

		int mdif = INT_MAX;
		int midx = 0;

		for (int i = 0; i < l; ++i) right += nums[i];

		for (int i = 0; i < l ; ++i) {
			left += nums[i];
			right -= nums[i];

			lavg = left / (i + 1);
			ravg = (l - i - 1 == 0) ? 0 : right / (l - i - 1);

			if (abs(lavg - ravg) < mdif) {
				mdif = abs(lavg - ravg);
				midx = i;
			}
			
		}

		return midx;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 4, 2, 0 }; // { 2, 5, 3, 9, 5, 3 };

	cout << sol.minimumAverageDifference(nums);

	cin >> c;

}