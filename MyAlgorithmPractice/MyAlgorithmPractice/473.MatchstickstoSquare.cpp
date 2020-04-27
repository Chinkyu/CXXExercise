#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class _Solution {
public:

	bool iteration(vector<int> &n, vector<bool> &i, int idx, int sum, int v) {
		int l = n.size();

		if (l <= idx) return false;
		if (sum > v) return false;
		if (sum + n[idx] == v) {
			cout << "Found it " << endl;
		}

		// have it 
		i[idx] = true;
		if (sum + n[idx] < v) {
			iteration(n, i, idx + 1, sum + n[idx], v);
		}
		
		// not have it 
		i[idx] = false;
		iteration(n, i, idx + 1, sum, v);


	}

	bool checkHalf(vector<int>& nums) {
		int s = 0;
		int l = nums.size();
		vector<bool> iter(l, false);

		for (auto it : nums) s += it;

		iteration(nums, iter, 0, 0, s / 2);
	}


	bool makesquare(vector<int>& nums) {
		int s = 0;
		int l = nums.size();
		vector<int> it(l, 0);

		for (auto it : nums) s += it;



	}
};

class Solution {
public:
	bool makesquare(vector<int>& nums) {
		int sum = 0;
		for (auto i : nums) sum += i;
		if (sum % 4 != 0 || sum == 0) return false;
		vector<int> used(nums.size(), 0);
		sort(nums.begin(), nums.end());
		reverse(nums.begin(), nums.end());
		if (!dfs(nums, 0, sum / 4, used)) return false;
		if (!dfs(nums, 0, sum / 4, used)) return false;
		if (!dfs(nums, 0, sum / 4, used)) return false;
		return true;

	}
	bool dfs(vector<int> &nums, int i, int target, vector<int> &used) {
		if (i >= nums.size()) return false;
		if (used[i] == 1) return dfs(nums, i + 1, target, used);
		if (target == nums[i]) {
			used[i] = 1;
			return true;
		}
		else if (target > nums[i]) {
			used[i] = 1;
			if (dfs(nums, i + 1, target - nums[i], used)) return true;
			used[i] = 0;
		}
		return dfs(nums, i + 1, target, used);
	}
};
