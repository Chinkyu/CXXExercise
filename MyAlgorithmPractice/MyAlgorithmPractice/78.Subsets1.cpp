#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	void dump(vector<int> &line) {
		for (auto it : line) {
			cout << it << " ";
		}
		cout << endl;
	}


	void iteration(vector<bool> &used, vector<vector<int>> &ans, vector<int> &line, vector<int> &nums, int idx, int start, int k) {

		if (idx == k) {
			ans.push_back(line);
			dump(line);
			return;
		}

		int n = nums.size();
		int st = start;
		//if (idx > 0) st = idx-1;

		for (int i = st; i < n; i++) {
			if (used[i] == false) {
				used[i] = true;
				line[idx] = nums[i];
				iteration(used, ans, line, nums, idx + 1, i, k);
				used[i] = false;
			}
		}

	}

	//vector<vector<int>> combine(int n, int k, vector<vector<int>> &ans) {
	//	vector<bool> used(n + 1, false);
	//	vector<int> line(k, 0);
	//	//vector<vector<int>> ans;

	//	iteration(used, ans, line, 0, n, k);
	//	return ans;
	//}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> answer;
		int n = nums.size();

		for (int i = 1; i <= n; ++i) {

			vector<bool> used(n, false);
			vector<int> line(i, 0);
			
			iteration(used, answer, line, nums, 0, 0, i);
		}

		answer.push_back(vector<int>(0, NULL));
		return answer;
	}
};

int main() {
	Solution sol;
	char c;
	vector<int> nums = { 1, 2, 3 };
	//vector<int> nums = { 30 };
	//vector<int> nums = { 0};

	vector<vector<int>> ans = sol.subsets(nums);


	for (auto it : ans) {
		for (auto jt : it) {
			cout << jt << ",";
		}
		cout << endl;
	}

	cin >> c;
}