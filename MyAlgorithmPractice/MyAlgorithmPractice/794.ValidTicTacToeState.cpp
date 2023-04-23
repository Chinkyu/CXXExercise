// 예외 케이스 때문에.. 시간이 좀 걸림.... 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	bool validTicTacToe(vector<string>& board) {
		int xCount = 0, oCount = 0;

		for (auto it : board) {
			for (auto jt : it) {
				if (jt == 'X') xCount++;
				else if (jt == 'O') oCount++;
			}
		}

		int diff = xCount - oCount;
		if (!(diff == 0 || diff == 1)) return false;

		// count bingo 
		int bingo_count = 0;
		vector<char> bingo_chars;
		for (int i = 0; i < 3; ++i) {
			if (board[i] == "OOO" || board[i] == "XXX") {
				bingo_count++;
				bingo_chars.push_back(board[i][0]);
			}
		}
		for (int i = 0; i < 3; ++i) {
			if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
				bingo_count++;
				bingo_chars.push_back(board[0][i]);
			}
		}

		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
			bingo_count++;
			bingo_chars.push_back(board[0][0]);
		}
		if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
			bingo_count++;
			bingo_chars.push_back(board[2][0]);
		}

		// X bingo -> try to by X
		if (bingo_count == 1 && diff == 0 && bingo_chars[0] == 'X') return false;

		// O bingo -> try to by O
		if (bingo_count == 1 && diff == 1 && bingo_chars[0] == 'O') return false;


		if (bingo_count >= 2 && (bingo_chars[0] != bingo_chars[1])) return false;

		return true;
	}
};

int main() {
	char c;

	Solution sol;

	vector<string> board = { "XXX","XOO","OO " }; // { "XXX", "   ", "OOO" }; // { "XOX", "O O", "XOX" };

	cout << sol.validTicTacToe(board);
	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}