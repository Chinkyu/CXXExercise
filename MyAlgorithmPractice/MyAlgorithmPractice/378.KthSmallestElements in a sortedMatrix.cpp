#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int l = matrix[0][0], h = matrix[n - 1][n - 1];
		int m = 0;

		while (l < h) {

			m = l + (h - l) / 2;
			int num = 0;
			for (int i = 0; i < n; i++) {
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), m) - matrix[i].begin();
				num += pos;
			}

			if (num < k) {
				l = m + 1;
			}
			else {
				h = m;
			}

		}
		return l;
	}
};

int main() {
	char c;
//	vector<vector<int>> m =
//	{ {1, 5, 9},
//		{10, 11, 13},
//		{12, 13, 15} };

	vector<vector<int>> m =
	{ {1, 5, 9},
		{10, 11, 14},
		{12, 14, 100} };

	Solution sol;

	cout << sol.kthSmallest(m, 8);

	cin >> c;


}