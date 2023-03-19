// 이거 기본적인 로직은 어렵지 안은데... 디버깅 하는데 어려움이 많았음..
// 한참을 왔다 갔다가 하면서.... 중복 되는경우 등등...
// 좀 시간이 많이 걸림. 


#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <map>

using namespace std;

// toRemove format : direction(1 horizental, 2 virtical),  h_index, vstar_index, vend_index)

class Solution {
public:

	void _makeBoardStable(vector<vector<int>> &board, vector<vector<int>> &toRemove) {

		for (auto it: toRemove) {
			if (it[0] == 1) { // horizental
				for (int i = it[2]; i <= it[3]; ++i) {  
					for (int j = it[1]; j >= 0; --j) {  // h_index : shift down vertically
						if (j != 0)
							board[j][i] = board[j - 1][i];
						else
							board[0][i] = 0;
					}
					//board[0][i] = 0;
				}
			}
			else {			// vertical
				for (int i = it[3]; i >= 0; --i) {
					if (i >= it[3] - it[2] + 1) 
						board[i][it[1]] = board[i - (it[3] - it[2] + 1)][it[1]];
					else 
						board[i][it[1]] = 0;
				}
			}
		}
	}

	void makeBoardStable2(vector<vector<int>> &board, vector<bool> &toCompact) {

		for (int i = 0; i < board[0].size(); ++i) {
			if (toCompact[i] == false) continue;

			int ridx = board.size() - 1;
			for (int j = board.size() - 1; j >= 0; --j) {
				while (ridx >= 0 && board[ridx][i] == 0) ridx--;
				if (ridx < 0) {
					board[j][i] = 0;
					continue;
				}
				board[j][i] = board[ridx--][i];
			}
		}
	}

	void makeZero(vector<vector<int>> &board, vector<vector<int>> &toRemove, vector<bool> &toCompact) 
	{
		for (auto it : toRemove) {
			if (it[0] == 1) { // horizental
				for (int i = it[2]; i <= it[3]; ++i) {
					board[it[1]][i] = 0;
					toCompact[i]= true;
				}
			}
			else {			// vertical
				for (int i = it[2]; i <= it[3]; ++i) {
					board[i][it[1]] = 0;
					toCompact[it[1]] = true;
				}
			}
		}
	}

	void findDistoryable(vector<vector<int>> &board, vector<vector<int>> &toRemove)
	{
		int rl = board.size();
		int cl = board[0].size();
		// scan row
		for (int i = 0; i < rl; ++i) {
			int prev = -1, same_count = 1, same_idx = -1;
			for (int j = 0; j < cl; ++j) {
				//if (board[i][j] == 0) { same_count = 1; prev = 0; continue; }

				if (board[i][j] == prev && prev != 0) {
					same_count++;
					same_idx = j;
				}
				else {  // not same - check how many
					if (same_count >= 3) {  // horizontal
						toRemove.push_back({ 1, i, same_idx - same_count + 1, same_idx });
					}
					same_count = 1;
					prev = board[i][j];
				}
			}
			// Have to do at the end of column
			if (same_count >= 3) {  // horizontal
				toRemove.push_back({ 1, i, same_idx - same_count + 1, same_idx });
			}
		}

		// scan column
		for (int j = 0; j < cl; ++j) {
			int prev = -1, same_count = 1, same_idx = -1;
			for (int i = 0; i < rl; ++i) {
				//if (board[i][j] == 0) { same_count = 1; prev = 0; continue; }

				if (board[i][j] == prev && prev != 0) {
					same_count++;
					same_idx = i;
				}
				else {  // not same - check how many
					if (same_count >= 3) { // vertical
						toRemove.push_back({ 2, j, same_idx - same_count + 1, same_idx });
					}
					same_count = 1;
					prev = board[i][j];
				}
			}
			// Have to do at the end of raw
			if (same_count >= 3) { // vertical
				toRemove.push_back({ 2, j, same_idx - same_count + 1, same_idx });
			}
		}
	}

	vector<vector<int>> candyCrush(vector<vector<int>>& board) {
		vector<vector<int>> toRemove;

		do {
			toRemove.clear();
			vector<bool> toCompact(board[0].size(), false);

			findDistoryable(board, toRemove);
			if (toRemove.size() == 0) break;
			makeZero(board, toRemove, toCompact);

			makeBoardStable2(board, toCompact);

			//printBoard(board);

		} while (true);
		return board;
	}

	void printBoard(vector<vector<int>>& board) {
		for (auto it : board) {
			for (auto jt : it) {
				cout.width(5);
				cout << " " << jt;
			}
			cout << endl;
		}
	}
};


int main() {
	char c;

	Solution sol;

	vector<vector<int>> board = {{110, 5, 112, 113, 114}, {210, 211, 5, 213, 214}, {310, 311, 3, 313, 314}, {410, 411, 412, 5, 414}, {5, 1, 512, 3, 3}, {610, 4, 1, 613, 614}, {710, 1, 2, 713, 714}, {810, 1, 2, 1, 1}, {1, 1, 2, 2, 2}, {4, 1, 4, 4, 1014}};

	vector<vector<int>> ans = sol.candyCrush(board);

	for (auto it : ans) {
		for (auto jt : it) {
			cout << " " << jt;
		}
		cout << endl;
	}

	//cout << sol.minimumSwap(s1, s2);

	cin >> c;
}