#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<bool> isVisited;
	vector<vector<int>> list;
	vector<int> n;
	int mLen;

//	Solution() : isVisited()

	void dumpNums() {
		for (auto i: n) {
			cout << i << " ";
		}
		cout << endl;
	}

	void iteration1(vector<int> &nums, int idx, int max) {
		if (idx == max) {
			list.push_back(vector<int>(n));
			dumpNums();
		}

		for (int i = 0; i < mLen; i++) {
			if (isVisited[i] == true) continue;

			isVisited[i] = true;
			n[idx] = nums[i];
			iteration1(nums, idx + 1, max);
			isVisited[i] = false;
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		mLen = nums.size();
		isVisited = vector<bool>(nums.size(), false);
		n = vector<int>(mLen, 0);
		list.clear();

		iteration1(nums, 0, mLen);
		return list;
	}
};

int main() {
	char c;
	vector<int> nums = { 1, 2, 3 };
	Solution s;

	s.permute(nums);

	cin >> c;
}