#include <iostream>
#include <vector>

using namespace std;

// Simple solution. 
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int sizeX = matrix.size();
		if (sizeX <= 0) return 0;
		int sizeY = matrix[0].size();
		int max = 0;

		vector <vector<int>> mat(sizeX + 1, vector<int>(sizeY + 1, 0));

		for (int i = 0; i < sizeX; ++i) {
			for (int j = 0; j < sizeY; ++j) {
				mat[i][j] = matrix[i][j] - '0';
			}
		}

		for (int i = 0; i < sizeX; ++i) {
			for (int j = 0; j < sizeY; ++j) {

				if (mat[i][j] == 0) continue;

				if (max == 0) max = 1;

				bool isNextIter = false;
				for (int k = 1; ; ++k) {
					for (int l = 0; l <= k; ++l) {
						if (i + k >= sizeX || j + l >= sizeY ||
							i + l >= sizeX || j + k >= sizeY) {
							isNextIter = true;
							break;
						}
						if (mat[i + k][j + l] == 0 || mat[i + l][j + k] == 0) {
							isNextIter = true;
							break;
						}
					}
					if (isNextIter == true) {
						break;
					}
					else {
						if ((k+1)*(k+1) > max) max = (k+1)*(k+1);
					}
				}
			}
		}

		return max;
	}
};


class _Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int sizeX = matrix.size();
		if (sizeX <= 0) return 0;
		int sizeY = matrix[0].size();
		int ans = 0;

		vector <vector<int>> mat(sizeX + 1, vector<int>(sizeY + 1, 0));
		vector <vector<int>> aMat(sizeX + 1, vector<int>(sizeY + 1, 0));

		for (int i = 0; i < sizeX; ++i) {
			for (int j = 0; j < sizeY; ++j) {
				mat[i + 1][j + 1] = matrix[i][j]-'0';
			}
		}

		int lu, l, u;
		for (int i = 1; i <= sizeX; ++i) {
			for (int j = 1; j <= sizeY; ++j) {
//				if (i - 1 < 0 || j - 1 < 0) lu = 0; else lu = matrix[i - 1][j - 1];
//				if (i - 1 < 0) l = 0; else l = matrix[i - 1][j];
//				if (j - 1 < 0) u = 0; else u = matrix[i][j - 1];

				lu = mat[i - 1][j - 1]; l = mat[i - 1][j]; u = mat[i][j - 1];

				if (lu == 0 && l == 0 && u == 0) {
					aMat[i][j] = mat[i][j];
				}
				else if(lu != 0 && l != 0 && u != 0) {
					//aMat[i][j] = aMat[i - 1][j - 1] + lu + l + u;
					aMat[i][j] = mat[i][j]+ aMat[i-1][j] + aMat[i][j-1] - aMat[i - 1][j - 1];

				} else if (lu == 0 && (l != 0 || u !=0)) {

					aMat[i][j] = (l != 0) ? aMat[i-1][j] + mat[i][j] : aMat[i][j-1] + mat[i][j];
				}

				if (aMat[i][j] > ans) {
					int sq = sqrt(aMat[i][j]);
					if (aMat[i][j] == sq * sq) ans = aMat[i][j];
//					ans = aMat[i][j];
				}
			}
		}

		for (auto it : aMat) {
			for (auto jt : it) {
				cout << jt << " ";
			}
			cout << endl;
		}
		return ans;
	}
};

int main() {
	Solution sol;
	char c;
//		vector<vector<char>> mat = {
//		{'1', '0', 1, 0, 0},
//		{1, 0, 1, 1, 1},
//		{1, 1, 1, 1, 1},
//		{1, 0, 0, 1, 0}
//		};

//		vector<vector<char>> mat = {
//		{'1', '1', '1', '1'},
//		{'1', '1', '1', '1'},
//		{'1', '1', '1', '1'}
//		};

//	vector<vector<char>> mat = { 
//		{'0', '0', '0', '1'}, 
//		{'1', '1', '0', '1'},
//		{'1', '1', '1', '1'}, 
//		{'0', '1', '1', '1'}, 
//		{'0', '1', '1', '1'} 
//	};

	vector<vector<char>> mat = {
		{ '1' }
	};


	cout << sol.maximalSquare(mat);

	cin >> c;
}