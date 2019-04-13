#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	vector<bool> isVisited;
	vector<vector<int>> list;
	set<vector<int>> s;
	vector<int> n;
	int mLen;

	//	Solution() : isVisited()

	void dumpNums() {
		for (auto i : n) {
			cout << i << " ";
		}
		cout << endl;
	}

	void iteration1(vector<int> &nums, int idx, int max) {
		if (idx == max) {
			s.insert(n);
			//list.push_back(vector<int>(n));
//			dumpNums();
		}

		for (int i = 0; i < mLen; i++) {
			if (isVisited[i] == true) continue;

			isVisited[i] = true;
			n[idx] = nums[i];
			iteration1(nums, idx + 1, max);
			isVisited[i] = false;
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		mLen = nums.size();
		isVisited = vector<bool>(nums.size(), false);
		n = vector<int>(mLen, 0);
		list.clear();

		iteration1(nums, 0, mLen);

		for (auto iter : s) {
			list.push_back(iter);
//			dumpNums
		}

		return list;
	}
};

int main() {
	char c;
	Solution s;
	vector<int> nums = { 1, 1, 2 };

	s.permuteUnique(nums);

//	for (auto iter : nums) {
//		for (auto jter : iter) cout << jter;
//		cout << endl;
//	}

	cin >> c;
}