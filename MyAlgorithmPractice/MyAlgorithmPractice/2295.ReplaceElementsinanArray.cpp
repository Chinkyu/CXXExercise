//   Neet little bit thinking.. with map 
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
	vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
		int l = nums.size();
		vector<int> ans(l, 0);

		unordered_map<int, int> m;  // <value, index> map

		for (int i = 0; i < nums.size(); ++i) {
			m[nums[i]] = i; // value, index
		}


		// <value, index> map : change value in same index

		for (auto it : operations) {
			int idx = m[it[0]];
			m.erase(it[0]);
			m[it[1]] = idx;
		}


		// make anser as index
		for (auto it : m) {
			ans[it.second] = it.first;
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 1,2,4,6 };
	vector<vector<int>> operations = { {1,3}, {4, 7}, {6, 1} };
	vector<int> ans =  sol.arrayChange(nums, operations);

	for (auto it : ans) {
		cout << it;
	}

	cin >> c;

}