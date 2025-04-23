//  ok : 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <set>
#include <list>
#include <regex>
#include <memory>
#include <functional>

using namespace std;

class Solution {
public:

    int traverse(vector<vector<int>>& grid, vector<vector<int>>& memo, int m, int n, int i, int j) {

        if (memo[i][j] != -1) return memo[i][j];

        int rmin = INT_MAX, dmin = INT_MAX;
        // right
        if (j < n - 1) {
            rmin = traverse(grid, memo, m, n, i, j + 1);
        }


        // down
        if (i < m - 1) {
            dmin = traverse(grid, memo, m, n, i + 1, j);
        }

        memo[i][j] = grid[i][j] + min(rmin, dmin);
        return memo[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> memo(m, vector<int>(n, -1));

        memo[m - 1][n - 1] = grid[m - 1][n - 1];

        return traverse(grid, memo, m, n, 0, 0);
    }
};

int main() {
    char c;
    Solution sol;
    //vector<vector<int>> grid = { {1, 3, 1}, {1, 5, 1}, {4, 2, 1} };
    vector<vector<int>> grid = { {0} };

    cout << sol.minPathSum(grid);

    cin >> c;
}