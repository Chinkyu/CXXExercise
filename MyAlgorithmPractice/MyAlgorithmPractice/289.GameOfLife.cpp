#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numOfAround(vector<vector<int>>& board, int x, int y) {
		int m = board.size();
		int n = board[0].size();

		int count = 0;
		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				if (i == 0 && j == 0) continue;
				if (x + i < 0 || x + i > m-1) continue;
				if (y + j < 0 || y + j > n - 1) continue;
				if (board[x + i][y + j] == 1) count++;
			}
		}

		return count;
	}


	void gameOfLife(vector<vector<int>>& board) {
		vector<vector<int>> ans = board;
		if (board.size() <= 0) return;

		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				ans[i][j] = board[i][j];
				if (board[i][j] == 1) {
					switch (numOfAround(board, i, j)) {
					case 0:
					case 1:
						ans[i][j] = 0;
						break;
					case 2:
					case 3:
						ans[i][j] = 1;
						break;
					default:
						ans[i][j] = 0;
						break;
					}
				}
				else {
					if (numOfAround(board, i, j) == 3) ans[i][j] = 1;
				}
			}
		}
		board = ans;
	}
};

int main() {
	char c;
	Solution sol;
	vector<vector<int>> m = {
		{0, 1, 0},
		{0, 0, 1},
		{1, 1, 1},
		{0, 0, 0}
	};

	sol.gameOfLife(m);

	for (auto it : m) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}
	cin >> c;
}