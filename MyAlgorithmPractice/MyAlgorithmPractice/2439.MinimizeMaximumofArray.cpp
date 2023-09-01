// 답봤고.. 대략 이해.... 
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
	int minimizeArrayValue(vector<int>& nums) {
		long long sum = 0, ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			ans = max(ans, (sum + i) / (i + 1));
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> nums = { 1, 13, 10, 12, 31 };

	cout << sol.countDistinctIntegers(nums);

	cin >> c;
}