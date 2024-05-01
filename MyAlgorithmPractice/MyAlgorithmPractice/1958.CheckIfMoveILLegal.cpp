//  ¥‰∫√¿Ω....  ?????
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	bool check(int i, int j, char e, char m, vector<vector<char>>& board, int r, int c) {
		int cnt = 0;
		r += i;
		c += j;
		while (r >= 0 && r < board.size() && c >= 0 && c < board[0].size()) {
			if (board[r][c] == '.') return false;
			else if (board[r][c] == m) cnt++;
			else if (board[r][c] == e) {
				if (cnt >= 1) return true;
				else return false;
			}
			r += i;
			c += j;
		}
		return false;
	}

	bool checkMove(vector<vector<char>>& board, int r, int c, char color) {

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (color == 'B') {
					if (check(i, j, 'B', 'W', board, r, c)) {
						return true;
					}
				}
				else if (check(i, j, 'W', 'B', board, r, c)) {
					return true;
				}
			}
		}

		return false;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> piles = { 4, 3, 6, 7 };

	cout << sol.minStoneSum(piles, 3);

	cin >> c;
}