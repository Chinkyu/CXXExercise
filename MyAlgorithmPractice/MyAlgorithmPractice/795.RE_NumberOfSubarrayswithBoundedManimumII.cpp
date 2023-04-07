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
	int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
		return count(nums, right) - count(nums, left - 1);
	}
	int count(const vector<int>& nums, int bound) {
		int ans = 0, cnt = 0;
		for (int x : nums) {
			cnt = x <= bound ? cnt + 1 : 0;
			ans += cnt;
		}
		return ans;
	}

};


class __Solution {
public:

	vector<int> nums_map;
	set < vector<int>> s;

	void subFind(vector<int> &nums, int sidx, int eidx) {

		for (int i = sidx; i <= eidx; ++i) {
			for (int j = i; j <= eidx; ++j) {

				if (i == j) {
					continue;
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

		int single_num = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (left <= nums[i] && nums[i] <= right) {
				nums_map[i] = 1;
				single_num++;
			}
			else if (right < nums[i]) {
				nums_map[i] = -1;
			}
		}

		// 
		int st = 0, ed = 0;
		do {
			while (st < nums.size() && nums_map[st] == -1) st++;

			ed = st;
			while (ed < nums.size() && nums_map[ed] != -1) ed++;

			//recurse(nums, m, st, st, ed - 1);
			if (st < nums.size()) subFind(nums, st, ed - 1);
			st = ed;
		} while (ed < nums.size());

		return s.size() + single_num;
	}
};

int main() {
	char c;

	Solution sol;

	//	vector<int> grid = { 73,55,36,5,55,14,9,7,72,52 };
	//	cout << sol.numSubarrayBoundedMax(grid, 32, 69);

	vector<int> grid = { 2, 9, 2, 5, 6 };
	cout << sol.numSubarrayBoundedMax(grid, 2, 8);

	
//	vector<int> grid = { 45, 2, 49, 6, 55, 73, 27, 17, 4, 71 };
//	cout << sol.numSubarrayBoundedMax(grid, 17, 33);



	cin >> c;
}