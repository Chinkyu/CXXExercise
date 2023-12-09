//  easy
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>

using namespace std;

class Solution {
public:
	vector<vector<int>> findWinners(vector<vector<int>>& matches) {
		unordered_map<int, int>  win, loose;

		for (auto &it : matches) {
			win[it[0]]++;
			loose[it[1]]++;
		}

		vector<int> allwin;
		vector<int> oneloose;

		for (auto &it : win) {
			if (loose.find(it.first) == loose.end()) allwin.push_back(it.first);
		}

		for (auto &it : loose) {
			if (it.second == 1) oneloose.push_back(it.first);
		}

		sort(allwin.begin(), allwin.end());
		sort(oneloose.begin(), oneloose.end());

		vector<vector<int>> ans(2);
		ans[0] = allwin;
		ans[1] = oneloose;

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
	vector<vector<int>> ans = sol.findWinners(matches);


	cin >> c;

}