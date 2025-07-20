// ok : straight forward 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:
	int minimumDeletions(vector<int>& nums) {
		int l = nums.size();

		int t_min = nums[0];
		int t_max = nums[0];
		int min_i = 0, max_i = 0;

		if (l <= 0) return nums[0];

		for (int i = 1; i < l; ++i) {
			if (t_min > nums[i]) {
				t_min = nums[i];
				min_i = i;
			}

			if (t_max < nums[i]) {
				t_max = nums[i];
				max_i = i;
			}
		}

		vector<int> v;
		v.push_back(min_i);
		v.push_back(max_i);

		sort(v.begin(), v.end());

		int ans = INT_MAX;
		ans = min(ans, v[1] + 1); // 1
		ans = min(ans, l - v[0]); // 2
		ans = min(ans, v[0] + 1  +  l - v[1]); // 3

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> nums = { 2,10,7,5,4,1,8,6 };

	cout << sol.minimumDeletions(nums);

	cin >> c;
}