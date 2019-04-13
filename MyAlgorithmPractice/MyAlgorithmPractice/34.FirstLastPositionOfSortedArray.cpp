#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int binary_search(vector<int>& nums, int s, int e, int target) {

		if (s == e) {
			return (nums[s] == target) ? s : -1;
		}

		int m = (s + e) / 2;
		if (target == nums[m]) {
			return m;
		}
		else if (target < nums[m]) {
			return binary_search(nums, s, m, target);
		}
		else {
			return binary_search(nums, m + 1, e, target);
		}

		return -1;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;
		int size = nums.size();
		if (size <= 0) {
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
		int idx = binary_search(nums, 0, size - 1, target);

		if (idx == -1) {
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
		else {
			int l = idx, r = idx;
			// try to left
			while (l-1 >= 0 && nums[idx] == nums[l-1]) --l;
			while (r+1 <= size - 1 && nums[idx] == nums[r+1]) ++r;
			res.push_back(l);
			res.push_back(r);
			return res;
		}
	}
};

int main() {
	Solution sol;
	char c;
	//vector<int> v = { 5, 7, 7, 8, 8, 10 };
	vector<int> v = {};

	vector<int> res = sol.searchRange(v, 5);

	cout << res[0] << " " << res[1] << endl;
	cin >> c;
}
