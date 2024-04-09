// easy 
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
	int sumOfBeauties(vector<int>& nums) {
		int l = nums.size();
		multiset<int> ls, rs;
		int ans = 0;

		ls.insert(nums[0]);
		for (int i = 2; i < l; ++i) rs.insert(nums[i]);

		for (int i = 1; i <= l - 2; ++i) {
			if (*ls.rbegin() < nums[i] && nums[i] < *rs.begin()) {
				ans += 2;
			}
			else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
				ans++;
			}

			ls.insert(nums[i]);
			// to remove only one when duplicated 
			rs.erase(rs.find(nums[i + 1]));
		}

		return ans;
	}
};


int main() {
	char c;
	Solution sol;

	vector<int> nums = { 2, 3, 4, 4, 5 }; // { 1, 2, 3};

	cout << sol.sumOfBeauties(nums);

	cin >> c;
}