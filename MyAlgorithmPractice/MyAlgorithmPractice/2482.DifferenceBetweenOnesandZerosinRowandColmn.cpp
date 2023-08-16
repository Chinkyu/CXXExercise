// easy  column/raw  헛갈리지 말고..
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
		int rl = grid.size(), cl = grid[0].size();
		vector<vector<int>> ans(rl, vector<int>(cl, 0));
		vector<int> rA(cl, 0);
		vector<int> cA(rl, 0);

		for (int i = 0; i < cl; ++i) {
			int one_zero = 0;
			for (int j = 0; j < rl; ++j) {
				if (grid[j][i] == 1) one_zero++;
				else one_zero--;
			}
			rA[i] = one_zero;
		}

		for (int i = 0; i < rl; ++i) {
			int one_zero = 0;
			for (int j = 0; j < cl; ++j) {
				if (grid[i][j] == 1) one_zero++;
				else one_zero--;
			}
			cA[i] = one_zero;
		}

		for (int i = 0; i < rl; ++i) {
			for (int j = 0; j < cl; ++j) {
				ans[i][j] = rA[j] + cA[i];
			}
		}
		
		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	vector<vector<int>> grid = { {1,1,1}, {1,1,1} }; // { {0, 1, 1}, { 1, 0, 1 }, { 0, 0, 1 } };
	vector<vector<int>> ans = sol.onesMinusZeros(grid);

	for (auto it : ans) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}

	cin >> c;
}