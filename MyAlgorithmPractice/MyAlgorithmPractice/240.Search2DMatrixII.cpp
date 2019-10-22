#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {

		if (!matrix.size()) return false;

		int len = matrix.size() + matrix[0].size();
		int r = 0;
		int c = matrix[0].size() - 1;
		while (r < matrix.size() && c < matrix[0].size()) {
			if (matrix[r][c] == target) return true;
			if (matrix[r][c] > target) c--;
			else if (matrix[r][c] < target) r++;
		}
		return false;
	}
};

class _Solution {
public:
	bool isFound = false;
	bool isInside(vector<vector<int>>& matrix, int x, int y, int x1, int y1, int target) {

		for (int i = x; i <= x1; ++i) {
			if (matrix[i][y] <= target && target <= matrix[i][y1]) return true;

		}
		//if (lh <= target && target <= rl) return true;
		return false;
	}

	bool twodSearch(vector<vector<int>>& matrix, int x, int y, int x1, int y1, int target) {
		if (isFound == true) return true;

		if (x == x1 && y == y1 && matrix[x][y] == target) {
				isFound = true;
				return true;
		} else if (x+1 == x1 && y+1 == y1) {
			for (int i = x; i <= x1; ++i) {
				for (int j = y; j < y1; ++j) {
					if (matrix[i][j] == target) {
						isFound = true;
						return true;
					}
				}
			}
			return false;
		}

		int mx = (x + x1) / 2;
		int my = (y + y1) / 2;

		if (target == matrix[mx][my]) {
			isFound = true;
			return true;
		}

		if (isInside(matrix, x, y, mx, my, target)) {
			return twodSearch(matrix, x, y, mx, my, target);
		}
		else if (isInside(matrix, x, y1, mx, y1, target)) {
			return twodSearch(matrix, x, y1, mx, y1, target);
		}
		else if (isInside(matrix, mx, y, x1, my, target)) {
			return twodSearch(matrix, mx, y, x1, my, target);
		}
		else {
			return twodSearch(matrix, mx, my, x1, y1, target);
		}
	}



	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int size = matrix.size();

		if (size <= 0) return false;
		isFound = false;

		twodSearch(matrix, 0, 0, size-1, size-1, target);
		return isFound;
	}
};

int main() {
	Solution sol;
	char c;
	vector<vector<int>> v =
		{
			{1, 4, 7, 11, 15},
			{2, 5, 8, 12, 19},
			{3, 6, 9, 16, 22},
			{10, 13, 14, 17, 24},
			{18, 21, 23, 26, 30}
	};

	cout << sol.searchMatrix(v, 3);

	cin >> c;
}