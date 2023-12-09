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
	int triangularSum(vector<int>& nums) {
		int l = nums.size();

		for (int i = l - 2; i >= 0; --i) {
			for (int j = 0; j <= i; ++j) {
				nums[j] = (nums[j] + nums[j + 1]) % 10;
			}
		}

		return nums[0];
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 5 };// { 1, 2, 3, 4, 5 };
	cout << sol.triangularSum(nums);

	cin >> c;

}