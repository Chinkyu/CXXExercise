// µð¹ö±ëÀÌ ÂÍ ±îÅ»... 
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
	vector<int> goodIndices(vector<int> & nums, int k) {
		int l = nums.size();
		vector<int> acc;
		vector<int> ans;

		if (l <= k * 2) return ans;
		if (k == 1) {
			for (int i = k; i < l- k; ++i) {
				ans.push_back(i);
			}
			return ans;
		}

		acc.push_back(0);
		for (int i = 1; i < l; ++i) {
			acc.push_back(nums[i] - nums[i - 1]);
		}

		int left_plus_num = 0;
		int right_min_num = 0;

		for (int i = 1; i < k; ++i) if (acc[i] > 0) left_plus_num++;
		for (int i = k + 1 + 1; i < k + k + 1; ++i) if (acc[i] < 0) right_min_num++;
		if (left_plus_num == 0 && right_min_num == 0) ans.push_back(k);

		for (int i = k+1; i < l - k; ++i) {
			// left
			if (acc[i - k] > 0) left_plus_num--;
			if (acc[i - 1] > 0) left_plus_num++;
			// right
			if (acc[i + 1] < 0) right_min_num--;
			if (acc[i + k] < 0) right_min_num++;

			if (left_plus_num == 0 && right_min_num == 0) ans.push_back(i);
		}

		return ans;
	}
};


int main() {
	char c;

	Solution sol;
	vector<int> nums = { 253747,459932,263592,354832,60715,408350,959296 }; // { 2, 1, 1, 2 }; // { 2, 1, 1, 1, 3, 4, 1 };

	vector<int> ans = sol.goodIndices(nums, 2);

	for (auto it : ans) {
		cout << it << " ";
	}


	cin >> c;
}