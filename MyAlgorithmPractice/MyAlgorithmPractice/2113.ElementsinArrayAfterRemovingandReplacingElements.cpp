// easy

#include <iostream>
#include <vector>
#include <unordered_map>
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
	vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
		int l = nums.size();

		vector<int> ans;

		for (int i = 0; i < queries.size(); ++i) {
			int time = queries[i][0];
			int index = queries[i][1];

			time %= l * 2;

			int sidx = 0, eidx = 0;
			if (time < l) { // mid left
				sidx = time, eidx = l;
			}
			else {			// mid right
				sidx = 0, eidx = time - l;
			}

			if (eidx <= sidx + index) {
				ans.push_back(-1);
			}
			else {
				ans.push_back(nums[sidx + index]);
			}
		}

		return ans;
	}
};


int main() {
	char c;

	Solution sol;
	//vector<int> nums = {0, 1, 2};
	//vector<vector<int>> queries = {{0, 2}, {2, 0}, {3, 2}, {5, 0}};

	vector<int> nums = {2};
	vector<vector<int>> queries = {{0, 0}, {1, 0}, {2, 0}, {3, 0}};


	vector<int> ans = sol.elementInNums(nums, queries);

	for (auto &it : ans) {
		cout << it << " ";
	}

	cin >> c;
}