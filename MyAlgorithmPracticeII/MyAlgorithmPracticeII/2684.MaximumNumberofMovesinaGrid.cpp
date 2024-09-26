// its ok : dfs and memoization 
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
#include <bitset>
#include <set>
#include <list>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:

    int traverse(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& memo) {
        int rl = grid.size();
        int cl = grid[0].size();

        if (memo[r][c] != -1) return memo[r][c];

        int num = 0;
        if (0 <= r - 1 && c + 1 < cl && grid[r][c] < grid[r - 1][c + 1]) {
            num = traverse(grid, r - 1, c + 1, memo);
        }

        if (0 <= r && c + 1 < cl && grid[r][c] < grid[r][c + 1]) {
            num = max(num, traverse(grid, r, c + 1, memo));
        }

        if (r + 1 < rl && c + 1 < cl && grid[r][c] < grid[r + 1][c + 1]) {
            num = max(num, traverse(grid, r + 1, c + 1, memo));
        }

        memo[r][c] = num + 1;
        return num + 1;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int rl = grid.size();
        int cl = grid[0].size();
        vector<vector<int>> memo(rl, vector<int>(cl, -1));

        int ans = 0;
        for (int i = 0; i < rl; ++i) {
            ans = max(ans, traverse(grid, i, 0, memo));
        }

        return ans - 1;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> grid = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};

    cout << sol.maxMoves(grid);
    cin >> c;
}