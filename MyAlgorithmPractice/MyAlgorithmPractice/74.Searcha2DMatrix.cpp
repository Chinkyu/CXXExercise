#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		// assert matrix is not null
		int m = matrix.size();
		if (m <= 0) return false;
		int n = matrix[0].size();
		if (n <= 0) return false;

		int row = 0;
		for (int i = 0; i < m; ++i) {
			if (matrix[i][0] == target) return true;
			if (matrix[i][0] > target) {
				row = i - 1;
				break;
			}
			row = i;
		}

		if (row < 0) return false;

		int st = 0, ed = n-1;
		do {
			if (st >= ed) {
				if (matrix[row][ed] == target) return true;
				return false;
			}
			int mid = (st + ed) / 2;
			if (matrix[row][mid] == target) {
				return true;
			} else if(matrix[row][mid] > target) {
				ed = mid - 1;
			}
			else {
				st = mid + 1;
			}
		} while (st >= 0 && st < n && ed >= 0 && ed < n);
		return false;
	}
};

int main() {
	Solution sol;
	char c;
	vector<vector<int>> mat = 
	{
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 50}
	};

	//vector<vector<int>> mat = { {1, 3} };

	cout << sol.searchMatrix(mat, 51);

	cin >> c;
}