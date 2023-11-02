//  memoization and traverse
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
	int n;
	vector<int> m;
	int traverse(vector<vector<int>> & grid, vector<vector<int>> & moveCost, int x, int y) {
		int xl = grid.size();
		int yl = grid[0].size();
		int v = grid[x][y];

		if (x == xl - 1) {
			m[v] = v;
			return v;
		}

		if (m[v] != INT_MAX) return m[v];

		int mind = INT_MAX;
		for (int i = 0; i < yl; ++i) {
			//int nval = grid[x + 1][i];
			int d = traverse(grid, moveCost, x + 1, i);
			d += moveCost[v][i];
			d += grid[x][y];

			mind = min(mind, d);
		}
		m[v] = mind;
		return mind;
	}


	int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
		int xl = grid.size();
		int yl = grid[0].size();

		n = xl * yl;
		m = vector<int>(n, INT_MAX);

		int tmin = INT_MAX;
		for (int i = 0; i < yl; ++i) {
			tmin = min(tmin, traverse(grid, moveCost, 0, i));
		}

		return tmin;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> grid = {{5, 3}, {4, 0}, {2, 1}};
	vector<vector<int>> moveCost = {{9, 8}, {1, 5}, {10, 12}, {18, 6}, {2, 4}, {14, 3}};
	cout << sol.minPathCost(grid, moveCost);

	cin >> c;

}