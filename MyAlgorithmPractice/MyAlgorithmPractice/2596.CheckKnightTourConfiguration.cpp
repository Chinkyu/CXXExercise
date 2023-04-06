//  어렵지 않게 풀림.. !!! 
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
	bool checkValidGrid(vector<vector<int>>& grid) {
		int n = grid.size();
		int x = 0, y = 0;

		for (int i = 0; i < n * n - 1; ++i) {
			if (grid[x][y]!= i) return false;

			bool isFound = false;
			for (int xi = -1; xi <= 1; xi += 2) {
				for (int yi = -1; yi <= 1; yi += 2) {
					int nx = x + xi * 1;
					int ny = y + yi * 2;
					if ((0 <= nx && nx < n) && (0 <= ny) &&(ny < n)) {
						if (grid[nx][ny] == i + 1) {
							x = nx;
							y = ny;
							isFound = true;
							goto out_loop;
						}
					}

					nx = x + xi * 2;
					ny = y + yi * 1;

					if ((0 <= nx && nx < n) && (0 <= ny) && (ny < n)) {
						if (grid[nx][ny] == i + 1) {
							x = nx;
							y = ny;
							isFound = true;
							goto out_loop;
						}
					}
				}
			}
out_loop:
			if (isFound == false) return false;
		}
		return true;
	}
};

int main() {
	char c;

	Solution sol;

	//vector<vector<int>> grid = { {0, 11, 16, 5, 20}, {17, 4, 19, 10, 15}, {12, 1, 8, 21, 6}, {3, 18, 23, 14, 9}, {24, 13, 2, 7, 22} };
	vector<vector<int>> grid = { {0, 3, 6},{5, 8, 1},{2, 7, 4}};

	cout << sol.checkValidGrid(grid);


	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}