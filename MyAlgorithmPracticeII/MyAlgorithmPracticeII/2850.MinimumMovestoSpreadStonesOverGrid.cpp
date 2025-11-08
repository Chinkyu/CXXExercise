// see answer : 
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
    int minimumMoves(vector<vector<int>>& grid) {
        // Base Case
        int t = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (grid[i][j] == 0)
                    t++;
        if (t == 0)
            return 0;

        int ans = INT_MAX;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (grid[i][j] == 0)
                {
                    for (int ni = 0; ni < 3; ++ni)
                    {
                        for (int nj = 0; nj < 3; ++nj)
                        {
                            int d = abs(ni - i) + abs(nj - j);
                            if (grid[ni][nj] > 1)
                            {
                                grid[ni][nj]--;
                                grid[i][j]++;
                                ans = min(ans, d + minimumMoves(grid));
                                grid[ni][nj]++;
                                grid[i][j]--;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};



lass _Solution{
public:

    int traverse(vector <vector<int>>& grid, vector<vector<int>>& mo, vector<vector<int>>& z, int moi, vector<int> zm) {
        int mox = mo[moi][0], moy = mo[moi][1];
        int remain = grid[mox][moy] - 1;

    }


    int minimumMoves(vector<vector<int>>&grid) {
        vector<vector<int>> mo, z;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] > 1) mo.push_back(vector<int> {i, j});
                if (grid[i][j] == 0) z.push_back(vector<int> {i, j});
            }
        }

        vector<int> zm(z.size(), -1);

    }
};

int main() {
    Solution sol;
    char c;
    vector<vector<int>> points = { {6, 2}, {4, 4}, {2, 6} };

    cout << sol.numberOfPairs(points);

    cin >> c;
}
