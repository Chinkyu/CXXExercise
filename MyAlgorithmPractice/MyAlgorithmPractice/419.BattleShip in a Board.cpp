#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	void biteX(vector<vector<char>>& board, int x, int y) {
		stack<pair<int, int>> s;
		int m = board.size();
		int n = board[0].size();

		s.push({ x, y });

		do {
			x = s.top().first;
			y = s.top().second; 
			s.pop();

			board[x][y] = 'Y';

			if (0 <= x - 1 && board[x - 1][y] == 'X') s.push({ x - 1, y });
			if (x + 1 < m && board[x + 1][y] == 'X') s.push({ x + 1, y });
			if (0 <= y - 1 && board[x][y-1] == 'X') s.push({ x, y-1 });
			if (y + 1 < n && board[x][y+1] == 'X') s.push({ x, y+1 });

		} while (s.size() > 0);
	}


	int countBattleships(vector<vector<char>>& board) {
		int ans = 0;
		int m = board.size();
		if (m <= 0) return 0;
		int n = board[0].size();
		if (n <= 0) return 0;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				// detect and change to 'Y'
				if (board[i][j] == 'X') {
					biteX(board, i, j);
					ans++;
				}
			}
		}
		return ans;
	}
};


int main() {
	char c;
	Solution sol;
	vector<vector<char>> v = 
	{
	{'X','.','.','X'},
	{'.','.','.','X'},
	{'.','.','.','X'}
	};

	cout << sol.countBattleships(v);

	cin >> c;
}