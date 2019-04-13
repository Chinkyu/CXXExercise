#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	void resetCount(vector<bool> &count) {
		for (int i = 0; i < 10; ++i) count[i] = false;
	}

	bool isValidSudoku(vector<vector<char>>& board) {
		vector<bool> count(10, false);

		// check 3X3 Block
		int sx, sy;

		char cIdx;
		for (int sx = 0; sx < 3; ++sx) {
			for (int sy = 0; sy < 3; ++sy) {

				resetCount(count);
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; ++j) {
						cIdx = board[sx * 3 + i][sy * 3 + j];
						if (cIdx == '.') continue;
						if (!count[cIdx - '0']) {
							count[cIdx - '0'] = true;
						}
						else {
							return false;
						}
					}
				}
			}
		}

		for (int i = 0; i < 9; ++i) {
			resetCount(count);
			for (int j = 0; j < 9; ++j) {
				cIdx = board[i][j];
				if (cIdx == '.') continue;
				if (!count[cIdx - '0']) {
					count[cIdx - '0'] = true;
				}
				else {
					return false;
				}
			}
		}

		for (int i = 0; i < 9; ++i) {
			resetCount(count);
			for (int j = 0; j < 9; ++j) {
				cIdx = board[j][i];
				if (cIdx == '.') continue;
				if (!count[cIdx - '0']) {
					count[cIdx - '0'] = true;
				}
				else {
					return false;
				}
			}
		}
		return true;
	}
};

int main() {
	Solution sol;
	char c;
	vector<vector<char>> v = 
	{
			{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
			{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
			{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
			{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
			{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
			{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
			{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
			{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
			{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};

	cout << sol.isValidSudoku(v);

	cin >> c;
}