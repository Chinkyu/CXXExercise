// 스킵 하자.. 이것은 좀 이상한 문제임 
// example 에  [2][2]를 두개 인정 하는것도 이상함... 말이 안됨.. 
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

	vector<int> nums_map;
	set < vector<int>> s;

	void recurse(vector<int> &nums, vector<int> m, int idx, int sidx, int eidx) {

		if (eidx == sidx) {
			vector<int> t_subarray;

			if (nums_map[sidx] == 1) {
				t_subarray.push_back(nums[sidx]);
				s.insert(t_subarray);
			}
			return;
		}


		if (idx > eidx) {
			bool isMaxExist = false;
			vector<int> t_subarray;
			for (int i = sidx; i <= eidx; ++i) {
				if (m[i] == 1) {
					t_subarray.push_back(nums[i]);
					if (nums_map[i] == 1) { isMaxExist = true; }
				}
			}

			if (isMaxExist == true) {
				if (t_subarray.size() != 0) s.insert(t_subarray);
			}

			return;
		}

		m[idx] = 0;
		recurse(nums, m, idx + 1, sidx, eidx);
		m[idx] = 1;
		recurse(nums, m, idx + 1, sidx, eidx);
	}

	void subFind(vector<int> &nums, int sidx, int eidx) {

		for (int i = sidx; i <= eidx; ++i) {
			for (int j = i; j <= eidx; ++j) {

				if (i == j) {
					vector<int> t_subarray;

					if (nums_map[i] == 1) {
						t_subarray.push_back(nums[i]);
						s.insert(t_subarray);
					}
					continue;
				}


				bool isMaxExist = false;
				vector<int> t_subarray;
				for (int k = i; k <= j; ++k) {
					t_subarray.push_back(nums[k]);
					if (nums_map[k] == 1) { isMaxExist = true; }
				}
				if (isMaxExist == true) {
					if (t_subarray.size() != 0) s.insert(t_subarray);
				}
			}
		}

	}


	int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
		nums_map = vector<int>(nums.size(), 0);
		vector<int> m = vector<int>(nums.size(), 0);
		s.clear();

		for (int i = 0; i < nums.size(); ++i) {
			if (left <= nums[i] && nums[i] <= right) {
				nums_map[i] = 1;
			}
			else if (right < nums[i]) {
				nums_map[i] = -1;
			}
		}

		// 
		int st = 0, ed = 0;
		do {
			while (nums_map[st] == -1) st++;

			ed = st;
			while (ed < nums.size() && nums_map[ed] != -1) ed++;

			//recurse(nums, m, st, st, ed - 1);
			subFind(nums, st, ed - 1);
			st = ed + 1;
		} while (ed < nums.size());

		return s.size();
	}
};



int main() {
	char c;

	Solution sol;

	vector<int> grid = { 73,55,36,5,55,14,9,7,72,52 };
	cout << sol.numSubarrayBoundedMax(grid, 32, 69);

//	vector<int> grid = { 2, 9, 2, 5, 6 };
//	cout << sol.numSubarrayBoundedMax(grid, 2, 8);


	cin >> c;
}