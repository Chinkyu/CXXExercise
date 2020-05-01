#include <iostream>
#include <set>
#include <vector>
#include <deque>

using namespace std;

enum state{
	NOT_STARTED,
	STARTED,
};


class Solution {
public:
	set<vector<int>> s;
	deque<int> dq;

	void _enumerate(vector<int> & nums, int st, int ed) {
		int l = ed - st + 1;
		for (int i = 2; i <= l; ++i) {
			for (int j = 0; j <= l - i; j++) {
				vector<int> v;
				for (int k = 0; k < i; ++k) {
					v.push_back(nums[st + j + k]);
				}
				s.insert(v);
			}
		}
	}

	void enumerate(vector<int> & nums, int st, int ed) {
		if (st == ed) {
			vector<int> v;
			if (dq.size() <= 0) return;
			for (auto it : dq) {
				v.push_back(it);
			}
			// not have ed
			if(v.size() > 1) s.insert(v);
			// have ed
			v.push_back(nums[ed]);
			if (v.size() > 1) s.insert(v);
			return;
		}

		enumerate(nums, st + 1, ed);
		dq.push_back(nums[st]);
		enumerate(nums, st + 1, ed);
		dq.pop_back();
	}

	vector<vector<int>> findSubsequences(vector<int>& nums) {
		s.clear();
		int l = nums.size();
		vector<vector<int>> ans;
		enum state stat = NOT_STARTED;    // state : 0 not started 

		if (l <= 1) return ans;

		// find increase substring
		int st = 0, ed = 0;
		for (int i = 1; i < l; ++i) {
			switch (stat) {
			case NOT_STARTED:
				if (nums[st] <= nums[i]) {
					stat = STARTED;
					ed = i;
				}
				break;
			case STARTED:
				if (nums[i-1] > nums[i] ) {
					stat = NOT_STARTED;
					enumerate(nums, st, ed);
					st = ed = i;
				}
				else if (i >= l - 1) {
					stat = NOT_STARTED;
					ed = i;
					enumerate(nums, st, ed);
					st = ed = i;
				} else {
					ed = i;
				}
				break;
			}
		}

		for (auto it : s) {
			ans.push_back(it);
		}
		return ans;
	}
};


int main() {
	char c;
	vector<int> v = { 4, 6, 7, 7 };
	Solution sol;

	vector<vector<int>> ans = sol.findSubsequences(v);

	for (auto it : ans) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}
	cin >> c;
}