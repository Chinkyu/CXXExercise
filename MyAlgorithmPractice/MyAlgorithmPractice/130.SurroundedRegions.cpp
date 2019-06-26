#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		int xn = board.size() - 1;
		if (xn <= 0) return;
		int yn = board[0].size() - 1;

		stack<pair<int, int>> st;

		for (int i = 0; i <= xn; ++i) {
			if (board[i][0] == 'O') {
				board[i][0] = '1';
				st.push(make_pair(i, 0));
			}
			if (board[i][yn] == 'O') {
				board[i][yn] = '1';
				st.push(make_pair(i, yn));
			}
		}

		for (int j = 0; j <= yn; ++j) {
			if (board[0][j] == 'O') {
				board[0][j] = '1';
				st.push(make_pair(0, j));
			}
			if (board[xn][j] == 'O') {
				board[xn][j] = '1';
				st.push(make_pair(xn, j));
			}
		}

		while (st.size() != 0) {
			int x = st.top().first;
			int y = st.top().second;
			st.pop();

			for (int i = -1; i <= 1; ++i) {
				for (int j = -1; j <= 1; ++j) {
					if (i == 0 && j == 0) continue;
					if (i != 0 && j != 0) continue;
					if ( 0 <= x + i && x + i <= xn && 
						0 <= y + j  && y + j <= yn ) {
						if (board[x + i][y + j] == 'O') {
							board[x + i][y + j] = '1';
							st.push(make_pair(x + i, y + j));
						}
					}
				}
			}
		}

		//return;

		// convert... 0 -> X, 1 -> 0
		for (int i = 0; i <= xn; ++i) {
			for (int j = 0; j <= yn; ++j) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				else if (board[i][j] == '1') board[i][j] = 'O';
			}

		}
	}
};

int main() {
	Solution sol;
	char c;

//	vector<vector<char>> mat = {  {'X', 'X', 'X', 'X'},
//                                  {'X', 'O', 'O', 'X'},
//                                  {'X', 'X', 'O', 'X'},
//                                  {'X', 'X', 'X', 'X'},
//                                  {'X', 'O', 'X', 'X'}
//    };

	vector<vector<char>> mat = { {'O', 'X', 'O'},
							     {'X', 'X', 'X'},
							     {'O', 'X', 'O'}
	};


    sol.solve(mat);

    for(auto it: mat) {
        for(auto jt: it) {
            cout << jt << " ";
        }
        cout << endl;
    }

	cin >> c;
}
