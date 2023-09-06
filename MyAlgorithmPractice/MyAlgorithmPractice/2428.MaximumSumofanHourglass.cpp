//  Easy... Sliding right.. 
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
	int getHourGlassSum(vector<vector<int>> & grid, int r, int c) {
		return grid[r][c] + grid[r][c + 1] + grid[r][c + 2]
			              + grid[r + 1][c + 1]
			+ grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2];
	}

	int maxSum(vector<vector<int>>& grid) {
		int r = grid.size();
		int c = grid[0].size();

		int tmax = 0;
		for (int i = 0; i <= r - 3; ++i) {
			int pSum = getHourGlassSum(grid, i, 0);
			tmax = max(pSum, tmax);
			for (int j = 1; j <= c - 3; ++j) {
				pSum = pSum - grid[i][j - 1] - grid[i + 1][j] - grid[i + 2][j - 1]
					            + grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
				tmax = max(pSum, tmax);
			}
		}

		return tmax;
	}
};

int main() {
	char c;

	Solution sol;
	vector<vector<int>> grid = { {6, 2, 1, 3},{4, 2, 1, 5},{9, 2, 8, 7},{4, 1, 2, 9} };

	cout << sol.maxSum(grid);

	cin >> c;
}