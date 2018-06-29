// PASS with ESCAPE_NUM : XXXX ;>

#include <iostream>
#include <vector>

#define ESCAPE_NUM -999

// Direction 
enum Direction {
	R, D, L, U
};

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int i, j;
		vector<int> result;

		int c = matrix.size();
		if (c <= 0) return result;

		int l = matrix[0].size();

		vector<vector<int>> myM(c+2, vector<int>(l+2));   // initialize additional two low and column

		for (i = 0; i < c + 2; i++) {
			myM[i][0] = ESCAPE_NUM;
			myM[i][l + 1] = ESCAPE_NUM;
		}
		for (j = 0; j < l + 2; j++) {
			myM[0][j] = ESCAPE_NUM;
			myM[c + 1][j] = ESCAPE_NUM;
		}

		for (i = 0; i < c; i++) {
			for (j = 0; j < l; j++) {
				myM[i + 1][j + 1] = matrix[i][j];
			}
		}

		Direction dr = R;
		i = 1; j = 0;
		int cnt = 0;
		while (cnt < c * l) {
			switch (dr) {
			case R:
				if (myM[i][j + 1] != ESCAPE_NUM) {
					result.push_back(myM[i][j + 1]);
					myM[i][++j] = ESCAPE_NUM;
					cnt++;
				}
				else {
					dr = D;
				}
				break;
			case D:
				if (myM[i+1][j] != ESCAPE_NUM) {
					result.push_back(myM[i+1][j]);
					myM[++i][j] = ESCAPE_NUM;
					cnt++;
				}
				else {
					dr = L;
				}
				break;
			case L:
				if (myM[i][j-1] != ESCAPE_NUM) {
					result.push_back(myM[i][j - 1]);
					myM[i][--j] = ESCAPE_NUM;
					cnt++;
				}
				else {
					dr = U;
				}
				break;
			case U:
				if (myM[i-1][j] != ESCAPE_NUM) {
					result.push_back(myM[i - 1][j]);
					myM[--i][j] = ESCAPE_NUM;
					cnt++;
				}
				else {
					dr = R;
				}
			}
		}

		return result;
	}
};

int main() {
	char c;
	vector<vector<int>> n; //= { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	Solution sol;

	vector<int> r = sol.spiralOrder(n);

	for (auto i: r) {
		cout << i << " ";
	}
	cout << endl;

	cin >> c;
}