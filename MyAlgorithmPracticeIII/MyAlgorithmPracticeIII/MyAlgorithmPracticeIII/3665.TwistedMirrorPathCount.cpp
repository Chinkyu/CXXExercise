// see answer : dp
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
    int mod = 1e9 + 7;
    int fn(vector<vector<int>>& grid, int i, int j, vector<vector<vector<int>>>& dp, int n, int m, int dir)
    {
        if (i >= n || j >= m) return 0;

        if (i == n - 1 && j == m - 1) return 1;

        if (dp[i][j][dir] != -1) return dp[i][j][dir];

        if (grid[i][j] == 1)
        {
            if (dir == 1)
            {
                return fn(grid, i + 1, j, dp, n, m, 0);

            }
            else if (dir == 0)
            {
                return fn(grid, i, j + 1, dp, n, m, 1);

            }
        }

        long long  move = 0;
        if (j + 1 < m && grid[i][j + 1] == 0)
        {
            move += fn(grid, i, j + 1, dp, n, m, 1);
        }
        else if (j + 1 < m && grid[i][j + 1] == 1)
        {
            move += fn(grid, i, j + 1, dp, n, m, 1);
        }

        if (i + 1 < n && grid[i + 1][j] == 0)
        {
            move += fn(grid, i + 1, j, dp, n, m, 0);
        }
        else if (i + 1 < n && grid[i + 1][j] == 1)
        {
            move += fn(grid, i + 1, j, dp, n, m, 0);
        }
        return dp[i][j][dir] = move % mod;
    }
    int uniquePaths(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(2, -1)));

        return fn(grid, 0, 0, dp, n, m, 0);



    }
};

class _Solution {
public:

    bool move(vector<vector<int>>& grid, int &i, int &j, int d) {

        // d: 1 right, 2 down
        int direction = d;
        int lr = grid.size();
        int lc = grid[0].size();

        do {
            if (direction == 1) {
                j = j + 1;
                if (j < 0 || lc <= j) return false;
                direction = 2;
            }
            else {  // direction == 2
                i = i + 1;
                if (i < 0 || lr <= i) return false;
                direction = 1;
            }
        } while (grid[i][j] == 1);

        return true;
    }

    int uniquePaths(vector<vector<int>>& grid) {

    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> buildings = { {0, 1}, {2, 1}, {3, 1}, {1, 4}, {2,4} };

    vector<int> ans = sol.findSmallestSetOfVertices(5, buildings);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
