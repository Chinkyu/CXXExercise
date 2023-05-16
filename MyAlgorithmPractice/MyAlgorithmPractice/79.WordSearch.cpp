//  여러 답을 찾기 위해 리커시브 사용...  풀엇던 문제인듯.. 

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

	bool isFound = false;
	void traverse(vector<vector<char>> &board, vector<vector<char>> &visit, string word, int widx, int x, int y) {
		int xW = board.size(), yW = board[0].size();

		if (isFound == true) return;

		int nx = 0, ny = 0;
		visit[x][y] = 1;

		if (widx == word.size() - 1) {
			isFound = true;
			visit[x][y] = 0;
			return;
		}

		//
		nx = x - 1; ny = y;
		if (((0 <= nx && nx < xW) && (0 <= ny && ny < yW)) &&
			(board[nx][ny] == word[widx+1] && visit[nx][ny] == 0)) {
			traverse(board, visit, word, widx + 1, nx, ny);
		}

		//
		nx = x + 1; ny = y;
		if (((0 <= nx && nx < xW) && (0 <= ny && ny < yW)) &&
			(board[nx][ny] == word[widx+1] && visit[nx][ny] == 0)) {
			traverse(board, visit, word, widx + 1, nx, ny);
		}

		//
		nx = x; ny = y - 1;
		if (((0 <= nx && nx < xW) && (0 <= ny && ny < yW)) &&
			(board[nx][ny] == word[widx+1] && visit[nx][ny] == 0)) {
			traverse(board, visit, word, widx + 1, nx, ny);
		}

		//
		nx = x; ny = y + 1;
		if (((0 <= nx && nx < xW) && (0 <= ny && ny < yW)) &&
			(board[nx][ny] == word[widx+1] && visit[nx][ny] == 0)) {
			traverse(board, visit, word, widx + 1, nx, ny);
		}

		visit[x][y] = 0;
	}


	bool exist(vector<vector<char>>& board, string word) {
		int xW = board.size(), yW = board[0].size();
		vector<vector<char>> visit(xW, vector<char>(yW, 0));

		for (int x = 0; x < xW; ++x) {
			for (int y = 0; y < yW; ++y) {
				if (word[0] == board[x][y]) {
					isFound = false;
					traverse(board, visit, word, 0, x, y);
					if(isFound) {
						return true;
					}
				}
			}
		}
		return false;
	}
};



// multiple path not work
class _Solution {
public:
	bool isExist(vector<vector<char>> &board, string word, int x, int y) {
		int xW = board.size(), yW = board[0].size();
		vector<vector<int>> visit(xW, vector<int>(yW, 0));

		if (word.size() == 1) return true;

		//for (int i = 1; i < word.size(); ++i) {
		int i = 1;
NEXT_IDX:
		for (int xa = -1; xa < 2; xa += 1) {
			for (int ya = -1; ya < 2; ya += 1) {
				if ((xa * ya != 0) || (xa == 0 && ya == 0)) continue;
				int nx = x + xa;
				int ny = y + ya;

				if (((0 <= nx && nx < xW) && (0 <= ny && ny < yW))) {
						if (board[nx][ny] == word[i] && visit[nx][ny] == 0) {
							x = nx;
							y = ny;
							visit[x][y] = 1;

							if (i == word.size() - 1) {
								return true;
							}
							else if (i >= word.size()) {
								return false;
							} else {
								i++;
								goto NEXT_IDX;
							}

						}
					}
				}
			}
		//}
		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		int xW = board.size(), yW = board[0].size();

		for (int x = 0; x < xW; ++x) {
			for (int y = 0; y < yW; ++y) {
				if (word[0] == board[x][y]) {
					if (isExist(board, word, x, y)) {
						return true;
					}
				}
			}
		}
		return false;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<char>> board = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
	
	//{ {'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'}};

	cout << sol.exist(board, "SEE");

	cin >> c;
}