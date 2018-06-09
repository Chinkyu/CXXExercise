// XXXX :  Áßº¹ »©±â....  : XXXX 


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<bool> isVisited;

	vector<int> fournum;
	vector<vector<int>> list;

	Solution() : fournum(4, 0) {

	}

	void dumpIsVisited() {

		for (auto i : isVisited) {
			cout << i << " ";
		}
		cout << endl;
	}

	void iteration(vector<int> & nums, int idx, int st, int target) {
		if (idx >= 4) {
			// check all... 
			if (target == fournum[0] + fournum[1] + fournum[2] + fournum[3]) {
				for (auto a : list) if (a == fournum) return;
//				if (!list.empty() && list.back() == fournum) return;

				list.push_back(vector<int>(fournum));
//				cout << fournum[0] << fournum[1] << fournum[2] << fournum[3] << endl;
//				dumpIsVisited();
			}
//			cout << fournum[0] << fournum[1] << fournum[2] << fournum[3] << endl;
			return;
		}

		for (int i = st; i < nums.size(); i++) {
			fournum[idx] = nums[i];
			iteration(nums, idx + 1, i+1, target);
		}
	}

	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		isVisited = vector<bool>(nums.size(), false);

		sort(nums.begin(), nums.end());
		iteration(nums, 0, 0, target);
		return list;
	}
};



int main() {
	Solution s;
	int i;

	cout << "test" << endl;

	vector<int> n = { 1, 0, -1, 0, -2, 2 };


	s.fourSum(n, 0);
	cin >> i;

}