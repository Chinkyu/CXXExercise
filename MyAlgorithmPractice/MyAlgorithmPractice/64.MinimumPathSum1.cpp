#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int>> accu(m, vector<int>(n, 0));


		accu[0][0] = grid[0][0];
		for (int i = 1; i < m; ++i) {
			accu[i][0] = grid[i][0] + accu[i - 1][0];
		}

		for (int j = 1; j < n; ++j) {
			accu[0][j] = grid[0][j] + accu[0][j-1];
		}

		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				accu[i][j] = grid[i][j] + ((accu[i - 1][j] < accu[i][j - 1]) ? accu[i - 1][j] : accu[i][j - 1]);
			}
		}
		return accu[m - 1][n - 1];
	}
};

int main() {
	Solution sol;
	char c;
	vector<vector<int>> mat = 
		{
			{1, 3, 1},
			{1, 5, 1},
			{4, 2, 1}
		};

	cout << sol.minPathSum(mat);

	cin >> c;
}