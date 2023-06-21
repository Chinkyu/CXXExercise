// 1 부터 시작 해서 마이너스로 늘려가면서 누적함... 
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
	//int max_distance = 0;
	void traverse(vector<vector<int>> &grid, int x, int y) {
		int num = -1;
		int n = grid.size();

		queue<pair<int, int>> q;
		q.push(make_pair(x, y));

		while (!q.empty()) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			int cur = grid[cx][cy];
			if (cur == 1) cur = 0;

			// -1, 0
			if (0 <= cx - 1 && cx - 1 < n && grid[cx -1][cy] <= 0) {
				if (grid[cx - 1][cy] < cur - 1 || grid[cx - 1][cy] == 0) {
					q.push(make_pair(cx - 1, cy));
					grid[cx - 1][cy] = cur - 1;
				}
			}
			// 0, -1
			if (0 <= cy - 1 && cy - 1 < n && grid[cx][cy - 1] <= 0) {
				if (grid[cx][cy - 1] < cur - 1 || grid[cx][cy - 1] == 0) {
					q.push(make_pair(cx, cy - 1));
					grid[cx][cy - 1] = cur - 1;
				}
			}

			// 1, 0
			if (0 <= cx + 1 && cx + 1 < n && grid[cx + 1][cy] <= 0) {
				if (grid[cx + 1][cy] < cur - 1 || grid[cx + 1][cy] == 0) {
					q.push(make_pair(cx + 1, cy));
					grid[cx + 1][cy] = cur - 1;
				}
			}

			// 0, 1
			if (0 <= cy + 1 && cy + 1 < n && grid[cx][cy + 1] <= 0) {
				if (grid[cx][cy + 1] < cur - 1 || grid[cx][cy + 1] == 0) {
					q.push(make_pair(cx, cy + 1));
					grid[cx][cy + 1] = cur - 1;
				}
			}
		}
	}

	int maxDistance(vector<vector<int>>& grid) {
		int n = grid.size();

		int oneCount = 0, zeroCount = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1) {
					traverse(grid, i, j);
					oneCount++;
				}
				else {
					zeroCount++;
				}
			}
		}

		if (oneCount <= 0 || zeroCount <= 0) return -1;

		int max_distance = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				max_distance = min(grid[i][j], max_distance);
			}
		}

		return max_distance * -1;

	}
};

int main() {
	char c;

	Solution sol;
	vector<vector<int>> grid = { {1, 0, 1},{0, 0, 0},{1, 0, 1} };
	cout << sol.maxDistance(grid);


	cin >> c;
}