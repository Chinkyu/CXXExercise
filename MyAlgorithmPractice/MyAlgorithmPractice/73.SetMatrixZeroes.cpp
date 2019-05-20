#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {

		// assert matrix is not null
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int> yl(m, 1);
		vector<int> xl(n, 1);

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					yl[i] = 0;
					xl[j] = 0;
				}
			}
		}

		for (int i = 0; i < m; ++i) {
			if (yl[i] == 0) {
				for (int j = 0; j < n; ++j) matrix[i][j] = 0;
			}
		}

		for (int j = 0; j < n; ++j) {
			if (xl[j] == 0) {
				for (int i = 0; i < m; ++i) matrix[i][j] = 0;
			}
		}
	}
};

int main() {
	Solution sol;
	char c;
	vector<vector<int>> mat = {
		{1, 1, 1},
		{1, 1, 0},
		{1, 1, 1}
	};

	sol.setZeroes(mat);

	for (auto it : mat) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}


	cin >> c;
}