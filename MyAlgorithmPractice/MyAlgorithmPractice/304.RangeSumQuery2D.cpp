#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
	vector<vector<int>> &m;
	vector<vector<int>> am;
	NumMatrix(vector<vector<int>>& matrix) : m(matrix) {
		int lx = m.size();
		if (lx <= 0) return;
		int ly = m[0].size();
		vector<vector<int>> tm(lx, vector<int>(ly, 0));
		vector<vector<int>> tm2(lx, vector<int>(ly, 0));

//		tm[0][0] = m[0][0];
//		for (int i = 0; i < lx; ++i) {
//			for (int j = 0; j < ly; ++j) {
//				tm[i][j] = _sumRegion(0, 0, i, j);
//			}
//		}
	
		tm2[0][0] = m[0][0];
		for (int i = 1; i < lx; ++i) tm2[i][0] = m[i][0] + tm2[i - 1][0];
		for (int i = 1; i < ly; ++i) tm2[0][i] = m[0][i] + tm2[0][i-1];
		for (int i = 1; i < lx; ++i) {
			for (int j = 1; j < ly; ++j) {
				tm2[i][j] = m[i][j] + tm2[i - 1][j] + tm2[i][j - 1] - tm2[i - 1][j - 1];
			}
		}
		
//		// compare
//		for (int i = 0; i < lx; ++i) {
//			for (int j = 0; j < ly; ++j) {
//				if (tm[i][j] != tm2[i][j]) cout << "Wrong " << i << " " << j << endl;
//			}
//		}
		am = tm2;
	}

	int _sumRegion(int row1, int col1, int row2, int col2) {
		int sum = 0;
		for (int i = row1; i <= row2; ++i) {
			for (int j = col1; j <= col2; ++j) {
				sum += m[i][j];
			}
		}
		return sum;
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int ans = 0;

		ans = am[row2][col2]; 
		if (row1 - 1 >= 0) ans -= am[row1 - 1][col2];
		if (col1 - 1 >= 0) ans -= am[row2][col1 - 1];
		if (row1 - 1 >= 0 && col1 - 1 >= 0) ans += am[row1 - 1][col1 - 1];

		return ans;
	}

};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
	char c;
	vector<vector<int>> matrix = {
		  {3, 0, 1, 4, 2},
		  {5, 6, 3, 2, 1},
		  {1, 2, 0, 1, 5},
		  {4, 1, 0, 1, 7},
		  {1, 0, 3, 0, 5}
	};
	NumMatrix* obj = new NumMatrix(matrix);

	cout << obj->sumRegion(2, 1, 4, 3);

	cin >> c;
}