// cc, cw  벡터방법으로 애초에 했었는데.. 뒤집고 뒤집는것으로 쉽게 해결함.... 
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
	void rotate(vector<vector<int>>& matrix) {
		// rotate diagonal 
		int n = matrix.size();
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				if (i == j) continue;
				swap(matrix[i][j], matrix[j][i]);
			}
		}

		// rotate vertically
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n / 2; ++j) {
				swap(matrix[i][j], matrix[i][n - j - 1]);
			}
		}
	}
};

int main() {
	char c;

	Solution sol;
	vector<vector<int>> grid = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
	sol.rotate(grid);
	for (auto it : grid) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}


	cin >> c;
}