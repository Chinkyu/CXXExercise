// Easy
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
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
	vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
		map<int, int> m;
		int l = arrays.size();
		vector<int> ans;

		for (auto &it : arrays) {
			for (auto &jt : it) {
				m[jt]++;
			}
		}

		for (auto &it: m) {
			if (it.second >= l) ans.push_back(it.first);
		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<vector<int>> times = {{1, 2, 3, 4, 5}, {6, 7, 8}};

	vector<int> ans = sol.longestCommonSubsequence(times);

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}