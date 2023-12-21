//  문제 이상함... 
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
	int maximumTop(vector<int>& nums, int k) {
		if (!k) return nums[0];

		int n = nums.size();
		int mx = 0;
		vector<int> prefix;
		for (int i : nums) {
			mx = max(mx, i);
			prefix.push_back(mx);
		}

		if (k > n) {
			if (n == 1) return k % 2 ? -1 : mx;
			return mx;
		}
		if (k == 1) return n == 1 ? -1 : nums[1];
		if (k == n) return prefix[n - 2];
		return max(prefix[k - 2], nums[k]);
	}
};


class Solution {
public:
	int maximumTop(vector<int>& nums, int k) {
		int l = nums.size();

		if (l <= k) return -1;

		int numsMax = 0, kMax = 0;
		for (int i = 0; i < l; ++i) {
			numsMax = max(numsMax, nums[i]);
			if (i < k-1) {
				kMax = max(kMax, nums[i]);
			}
		}

		return kMax;
	}
};

int main() {
	char c;

	Solution sol;


	vector<int> nums = { 5,2,2,4,0,6 };
	cout << sol.maximumTop(nums, 4);

	cin >> c;

}