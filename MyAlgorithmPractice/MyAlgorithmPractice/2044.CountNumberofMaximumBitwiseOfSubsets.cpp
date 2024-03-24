//  easy : recursive 
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

// not this way
class _Solution {
public:
	int countMaxOrSubsets(vector<int>& nums) {
		int l = nums.size();

		int bw = 0;
		for (auto &it : nums) bw |= it;

		int ans = 0;
		for (int i = 0; i < l; ++i) {
			int cw = 0;
			for (int j = i; j < l; ++j) {
				cw |= nums[j];
				if (cw == bw) ans++;
			}
		}

		return ans;
	}
};

class Solution {
public:

	void traverse(vector<int> &nums, int idx, int l, int bw, int cw) {

		if (idx == l) {
			if (bw == cw) cnt++;
			return;
		}


		// not choose
		traverse(nums, idx + 1, l, bw, cw);

		// choose 
		cw |= nums[idx];
		traverse(nums, idx + 1, l, bw, cw);



	}
	
	int cnt = 0;

	int countMaxOrSubsets(vector<int>& nums) {
		int l = nums.size();

		int bw = 0;
		for (auto &it : nums) bw |= it;

		cnt = 0;
		traverse(nums, 0, l, bw, 0);
		return cnt;
	}
};


int main() {
	char c;
	Solution sol;

	vector<int> nums = { 3, 1 };

	cout << sol.countMaxOrSubsets(nums);

	cin >> c;
}