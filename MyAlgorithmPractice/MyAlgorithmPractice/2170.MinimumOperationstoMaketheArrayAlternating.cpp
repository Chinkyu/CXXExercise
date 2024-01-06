// easy : 
//  max, 2nd max  를 찾는 더 좋은 방법이 있을텐데.. !!!!!!
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	int minimumOperations(vector<int>& nums) {
		int l = nums.size();
		unordered_map<int, int> oCount, eCount;

		if (l <= 1) return 0;

		int el = l / 2;
		int ol = l - el;

		for (int i = 0; i < l; ++i) {
			if (i % 2 == 1) {
				eCount[nums[i]]++;
			}
			else {
				oCount[nums[i]]++;
			}
		}

		int oMaxNum = -1, oMaxIter = 0;
		for (auto &it : oCount) {
			if (it.second >= oMaxIter) {
				oMaxNum = it.first;
				oMaxIter = it.second;
			}
		}

		int oSndNum = -1, oSndIter = 0;
		for (auto &it : oCount) {
			if (it.first == oMaxNum) continue;
			if (it.second >= oSndIter) {
				oSndNum = it.first;
				oSndIter = it.second;
			}
		}


		int eMaxNum = -1, eMaxIter = 0;
		for (auto &it : eCount) {
			if (it.second >= eMaxIter) {
				eMaxNum = it.first;
				eMaxIter = it.second;
			}
		}

		int eSndNum = -1, eSndIter = 0;
		for (auto &it : eCount) {
			if (it.first == eMaxNum) continue;
			if (it.second >= eSndIter) {
				eSndNum = it.first;
				eSndIter = it.second;
			}
		}

		int ans = 0;
		if (oMaxNum == eMaxNum) {
			int ans1 = 0;
			ans1 += ol - oMaxIter;
			ans1 += el - eSndIter;

			int ans2 = 0;
			ans2 += ol - oSndIter;
			ans2 += el - eMaxIter;

			ans = min(ans1, ans2);

		}
		else {
			ans += ol - oMaxIter;
			ans += el - eMaxIter;
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> nums = { 2, 2 };

	cout << sol.minimumOperations(nums);

	cin >> c;
}