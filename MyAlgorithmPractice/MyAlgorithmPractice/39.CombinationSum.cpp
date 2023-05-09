// 다해보기.. 타임 아웃 날줄 알았는데.. 패스됨... 
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
	set<vector<int>> ans_set;
public:
	void traverse(vector<int> &candidates, int idx, vector<int> arr, int sub_sum, int target) {
		int t_sum = 0;

		if (sub_sum == target) {
			ans_set.insert(arr);
			return;
		}

		if (idx >= candidates.size()) return;

		int it_num = 0;
		// no adding
		traverse(candidates, idx + 1, arr, sub_sum + t_sum, target);

		while (sub_sum + t_sum <= target) {
			arr.push_back(candidates[idx]);
			sub_sum += candidates[idx];
			traverse(candidates, idx + 1, arr, sub_sum + t_sum, target);
		};
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> arr;
		vector<vector<int>> ans;

		sort(candidates.begin(), candidates.end());

		traverse(candidates, 0, arr, 0, target);

		for (auto it : ans_set) {
			ans.push_back(it);
		}
		return ans;
	}
};



int main() {
	char c;

	Solution sol;

	vector<int> candidates = { 2, 3, 6, 7 };
	vector<vector<int>> ans = sol.combinationSum(candidates, 7);

	for (auto it : ans) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}

	cin >> c;
}