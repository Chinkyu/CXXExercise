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
	vector<int> getAverages(vector<int>& nums, int k) {
		int l = nums.size();
		vector<int> ans(l, -1);

		if (l < k * 2 + 1) return ans;

		long long sum = 0;
		int ci = k;
		for (int i = ci - k; i <= ci + k; ++i) sum += nums[i];
		ans[ci] = sum / (k * 2 + 1);

		ci++;
		for (; ci + k < l; ci++) {
			sum -= nums[ci - k - 1];
			sum += nums[ci + k];
			ans[ci] = sum / (k * 2 + 1);
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 7,4,3,9,1,8,5,2,6 };

	vector<int> ans = sol.getAverages(nums, 3);

	for (auto &it : ans) {
		cout << it << " ";
	}


	cin >> c;
}