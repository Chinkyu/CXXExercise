#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class _Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> visited;
	void dfs(vector<vector<int>>& matrix, int x, int y, int pre, int preval) {
		if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()
			|| matrix[x][y] < pre || (visited[x][y] & preval) == preval)
			return;
		visited[x][y] |= preval;
		if (visited[x][y] == 3) res.push_back({ x, y });
		dfs(matrix, x + 1, y, matrix[x][y], visited[x][y]); dfs(matrix, x - 1, y, matrix[x][y], visited[x][y]);
		dfs(matrix, x, y + 1, matrix[x][y], visited[x][y]); dfs(matrix, x, y - 1, matrix[x][y], visited[x][y]);
	}

	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		if (matrix.empty()) return res;
		int m = matrix.size(), n = matrix[0].size();
		visited.resize(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) {
			dfs(matrix, i, 0, INT_MIN, 1);
			dfs(matrix, i, n - 1, INT_MIN, 2);
		}
		for (int i = 0; i < n; i++) {
			dfs(matrix, 0, i, INT_MIN, 1);
			dfs(matrix, m - 1, i, INT_MIN, 2);
		}
		return res;
	}
};



class Solution {
public:
	void traverse(int x, int y, vector<vector<int>> & matrix, vector<vector<char>> &map, char cm) {

		stack<int> sx, sy;
		int m = matrix.size(), n = matrix[0].size();
		
		sx.push(x); sy.push(y);
		do {
			x = sx.top(); sx.pop();
			y = sy.top(); sy.pop();
			for (int h = -1; h <= 1; h += 1) {
				for (int v = -1; v <= 1; v += 1) {
					if ((h != 0 && v != 0)
						|| (h == 0 && v == 0)) continue;  // only 4 direction
					// left, right, up, down

					// check sanity
					if (0 <= x + h && x + h < m && 0 <= y + v && y + v < n) {

					}
					else {
						continue;
					}

					if (x + h <= 0 && map[x + h][y + v] != cm && matrix[x + h][y + v] >= matrix[x][y]) {
						if (map[x + h][y + v] == '0') {
							map[x + h][y + v] = cm;
							sx.push(x + h); sy.push(y + v);
						}
						else if (map[x + h][y + v] == cm) {
							continue;
						}
						else {
							map[x+h][y + v] = 'b';
							sx.push(x + h); sy.push(y + v);
						}
					}
				}
			}
		} while (sx.size() > 0);

	}


	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<vector<int>> ans;
		int m = matrix.size();
		if (m <= 0) return ans;
		int n = matrix[0].size();
		if (m <= 0) return ans;

		vector<vector<char>> map(m, vector<char>(n, '0'));


		for (int i = 0; i < m; ++i) {
			traverse(i, 0, matrix, map, 'a');
			traverse(i, n - 1, matrix, map, 'p');
		}

		for (int i = 0; i < n; ++i) {
			traverse(0, i, matrix, map, 'a');
			traverse(m-1, i, matrix, map, 'p');
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (map[i][j] == 'b') ans.push_back({ i, j });
			}
		}

	}
};

int main() {
	char c;
	Solution sol;
	vector<vector<int>> vm =
	{
	{1,   2,   2,  3,   5},
	{3,   2,   3,  4,   4},
	{2,   4,   5,  3,   1},
	{6,   7,   1,  4,   5},
	{5,   1,   1,  2,   4}};

	vector<vector<int>> ans = sol.pacificAtlantic(vm);

	for (auto it : ans) {
		cout << it[0] << " " << it[1] << endl;
	}

	cin >> c;
}