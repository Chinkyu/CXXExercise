// 답봤음 : 내용 확인 해야함.. 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {

public:
	bool removeOnes(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();

		// If any cell on the first row has 1, flipping that column. 

		for (int i = 0; i < m; i++) {
			if (grid[0][i] == 1) {
				// flipping that column
				for (int j = 0; j < n; j++) {
					grid[j][i] = !grid[j][i];
				}
			}
		}

		// Now, all other rows should be either all 0's or all 1's. If not, than that's impossible to find a solution 

		for (int i = 1; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < m; j++) {
				sum += grid[i][j];
			}

			if (sum != 0 && sum != m) {
				return false;
			}
		}

		return true;

	}
};

int main() {
	char c;

	Solution sol;
	vector<string> words = { "lc", "cl", "gg" };

	cout << sol.longestPalindrome(words);

	cin >> c;
}