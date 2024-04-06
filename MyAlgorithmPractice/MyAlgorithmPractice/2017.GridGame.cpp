//  easy 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
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
	long long gridGame(vector<vector<int>>& grid) {
		int l = grid[0].size();

		vector<vector<long long>> c(2, vector<long long>(l, 0));

		c[0][0] = grid[0][0];
		c[1][0] = grid[1][0];
		long long upSum = grid[0][0];
		for (int i = 1; i < l; ++i) {
			c[0][i] += c[0][i - 1] + grid[0][i];
			upSum += grid[0][i];
			c[1][i] += c[1][i - 1] + grid[1][i];
		}

		long long b2min = upSum - c[0][0]; 
		for (int i = 1; i < l; ++i) {
			long long tmax = max(upSum - c[0][i], c[1][i - 1]);
			b2min = min(b2min, tmax);
		}

		return b2min;
	}
};

int main() {
	char c;
	Solution sol;

	vector<vector<int>> grid = {{2, 5, 4}, {1, 5, 1}};

	cout << sol.gridGame(grid);

	cin >> c;
}