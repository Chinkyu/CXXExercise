//  vector : memory space error , map -> OK
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


// Space Error 
class _Solution {
public:
	int destroyTargets(vector<int>& nums, int space) {
		vector<int> r(space, 0);
		vector<int> r_min(space, INT_MAX);

		for (auto it : nums) {
			r[it%space]++;
			r_min[it%space] = min(r_min[it%space], it);
		}

		int max_r_idx = -1;
		int max_r_val = -1;

		for (int i = 0; i < space; ++i) {
			if (max_r_val < r[i]) {
				max_r_idx = i;
				max_r_val = r[i];
			}
			else if (max_r_val == r[i]) {
				if (r_min[max_r_idx] > r_min[i]) {
					max_r_idx = i;
					max_r_val = r[i];
				}
			}
		}

		return r_min[max_r_idx];
	}
};

class Solution {
public:
	int destroyTargets(vector<int>& nums, int space) {
		map<int, int> r;
		map<int, int> r_min;

		for (auto it : nums) {
			r[it%space]++;
			if (r_min.find(it%space) == r_min.end()) {
				r_min[it%space] = it;
			}
			else {
				r_min[it%space] = min(r_min[it%space], it);
			}
		}

		int max_r_idx = -1;
		int max_r_val = -1;

		for (auto it : r) {
			if (max_r_val < it.second) {
				max_r_idx = it.first;
				max_r_val = it.second;
			}
			else if (max_r_val == it.second) {
				if (r_min[max_r_idx] > r_min[it.first]) {
					max_r_idx = it.first;
					max_r_val = it.second;
				}
			}
		}

		return r_min[max_r_idx];
	}
};


int main() {
	char c;

	Solution sol;
	vector<int> nums = { 6, 2, 5 }; // { 1, 3, 5, 2, 4, 6 }; // { 6, 2, 5 };

	cout << sol.destroyTargets(nums, 100);

	cin >> c;
}