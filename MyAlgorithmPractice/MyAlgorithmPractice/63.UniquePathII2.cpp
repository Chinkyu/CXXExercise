#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
		// Assert obstacleGrid is not null
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (obstacleGrid[i][j] == 1) obstacleGrid[i][j] = -1;
			}
		}

		for (int i = 0; i < m; ++i) {
			if(obstacleGrid[i][0] == -1 ) break;
			obstacleGrid[i][0] = 1;
		}
		for (int i = 0; i < n; ++i) {
			if (obstacleGrid[0][i] == -1) break;
			obstacleGrid[0][i] = 1;
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (obstacleGrid[i][j] != -1) {
					obstacleGrid[i][j] = 
						((obstacleGrid[i - 1][j] == -1) ? 0 : obstacleGrid[i - 1][j]) 
						+ ((obstacleGrid[i][j - 1] == -1) ? 0 : (obstacleGrid[i][j - 1]));
				}
			}
		}
		return  obstacleGrid[m - 1][n - 1];
	}

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		// Assert obstacleGrid is not null
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

		vector < vector<long long>> mat(m, vector<long long>(n, 0));

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (obstacleGrid[i][j] == 1) mat[i][j] = -1;
			}
		}

		for (int i = 0; i < m; ++i) {
			if (mat[i][0] == -1) break;
			mat[i][0] = 1;
		}
		for (int i = 0; i < n; ++i) {
			if (mat[0][i] == -1) break;
			mat[0][i] = 1;
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (mat[i][j] != -1) {
					mat[i][j] =
						((mat[i - 1][j] == -1) ? 0 : mat[i - 1][j])
						+ ((mat[i][j - 1] == -1) ? 0 : (mat[i][j - 1]));
				}
			}
		}

		int ret = (mat[m - 1][n - 1] == -1) ? 0 : mat[m - 1][n - 1];
		return ret;
	}
};

int main() {
	Solution sol;
	char c;
	vector<vector<int>> mat = {
		{0,0,0},
  {0,1,0},
  {0,0,0}
	};

	cout << sol.uniquePathsWithObstacles(7, 3);

	cin >> c;
}