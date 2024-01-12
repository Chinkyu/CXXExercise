// eash : sliding  
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	vector<int> maxScoreIndices(vector<int>& nums) {
		int lscore = 0, rscore = 0;

		for (auto &it : nums) rscore += it;

		vector<int> ans;
		int maxScore = rscore;
		ans.push_back(0);
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == 0) {
				lscore++;
			}
			else {   // if 1
				rscore--;
			}

			if (lscore + rscore > maxScore) {
				ans.clear();
				ans.push_back(i+1);
				maxScore = lscore + rscore;
			}
			else if (lscore + rscore == maxScore) {
				ans.push_back(i+1);
			}

		}

		return ans;
	}
};


int main() {
	char c;

	Solution sol;

	vector<int> nums = {1,1};
	vector<int> ans =  sol.maxScoreIndices(nums);

	for (auto &it : ans) {
		cout << it << " ";
	}

	cin >> c;
}