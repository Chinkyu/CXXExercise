#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	//vector<vector<char>>& board;
	bool isFound = false;

	void iteration(vector<vector<char>>& board, vector<vector<bool>> &vmap, stack<pair<int, int>>& history, string word, int vi, int vj, int wi) {

		if (isFound == true) return;

		int m = board.size();
		int n = board[0].size();
		
		// push stack 
		history.push(pair<int, int>(vi, vj));
		vmap[vi][vj] = true;
		wi++;

		if (wi >= word.size()) {
			isFound = true;
			return;
		}

		// check 4 direction 
		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				if (i != 0 && j != 0) continue;  // remove corner;

				if (0 <= vi + i && vi + i < m &&
					0 <= vj + j && vj + j < n) {
					if (word[wi] == board[vi + i][vj + j] && vmap[vi+i][vj+j] == false) {
						iteration(board, vmap, history, word, vi + i, vj + j, wi);
					}
				}

			}
		}

		history.pop();
		vmap[vi][vj] = false;
	}


    
    bool exist(vector<vector<char>>& board, string word) {
        int ws = word.size();
        int m = board.size();
        int n = board[0].size();
		vector<vector<bool>> vmap (m, vector<bool>(n, false));
		
		isFound = false;

		stack <pair<int, int>> history;

        // find first char
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
				if (word[0] == board[i][j]) {
					// trigger iteration 
					iteration(board, vmap, history, word, i, j, 0);
					if (isFound == true) return true;
				}
            }
        }
		return false;
    }
};

int main() {
    Solution sol;
    char c;

	//vector<vector<char>> mat =
	//{
	//		{'A', 'B', 'C', 'E'},
	//		{'S', 'F', 'C', 'S'},
	//		{'A', 'D', 'E', 'E'}
	//};

	vector<vector<char>> mat =
	{
			{'A', 'B'},
			{'C', 'D'}
	};

	cout << sol.exist(mat, "ABCD");

    cin >> c;
}
