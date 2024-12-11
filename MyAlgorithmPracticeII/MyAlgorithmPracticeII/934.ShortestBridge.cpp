//   ¥‰∫√¿Ω : dfs and dijkstra
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
#include <functional>

using namespace std;


class Solution {
public:

    int r[4] = { -1 , 0, 1, 0 };
    int c[4] = { 0 ,1 , 0 , -1 };

    void dfs(int row, int col, vector<pair<int, int>>& v, vector<vector<int>>& vis, vector<vector<int>>& grid)
    {
        int n = vis[0].size();
        vis[row][col] = 1;
        v.push_back({ row , col });
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + r[i];
            int ncol = col + c[i];

            if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < n and vis[nrow][ncol] == 0 and grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, v, vis, grid);
            }
        }

    }

    int shortestBridge(vector<vector<int>>& grid) {

        vector<pair<int, int>> v;
        vector<pair<int, int>> v1;
        vector<pair<int, int>> v2;
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 and vis[i][j] == 0)
                {
                    dfs(i, j, v, vis, grid);
                    if (flag == 0)
                    {
                        v1 = v;
                        flag = 1;
                        v.clear();
                    }
                    else
                    {
                        v2 = v;
                    }
                }

            }

        }
        //printed just to check the co-ordinates****
        //for(auto it: v1)
        //{
        //    cout<<it.first<<" "<<it.second<<endl;
        //}
        //for(auto it: v2)
        //{
        //    cout<<it.first<<" "<<it.second<<endl;
        //}
        int ans = 1e9;


        for (auto it : v1)
        {
            int row1 = it.first;
            int col1 = it.second;

            for (auto itt : v2)
            {
                int row2 = itt.first;
                int col2 = itt.second;

                int dist = abs(row1 - row2) + abs(col1 - col2);
                dist--;
                ans = min(ans, dist);
            }
        }

        return ans;
    }
};

//:: ckkang : Timeout 
class Solution {
public:

    void findOne(vector<vector<int>>& grid, int& r, int& c) {
        int lr = grid.size();
        int lc = grid[0].size();

        for (int i = 0; i < lr; ++i) {
            for (int j = 0; j < lc; ++j) {
                if (grid[i][j] == 1) {
                    r = i;
                    c = j;
                    return;
                }
            }
        }

    }


    void gatherIsland(vector<vector<int>>& grid, int r, int c, vector<pair<int, int>>& v) {
        int rl = grid.size();
        int cl = grid[0].size();

        queue<pair<int, int>> q;
        q.push(make_pair(r, c));

        while (q.size() != 0) {
            int ri = q.front().first;
            int ci = q.front().second;
            v.push_back({ ri, ci });
            grid[ri][ci] = 2;
            q.pop();

            // up
            if (0 <= ri - 1 && grid[ri - 1][ci] == 1) q.push({ ri - 1, ci });
   
            // down
            if (ri + 1 < rl && grid[ri + 1][ci] == 1) q.push({ ri + 1, ci });

            // left
            if (0 <= ci - 1 && grid[ri][ci - 1] == 1) q.push({ ri, ci - 1 });

            // right
            if (ci + 1 < cl && grid[ri][ci + 1] == 1) q.push({ ri, ci + 1 });
        }

        return;
    }

    int shortestBridge(vector<vector<int>>& grid) {

        // find 1st island
        int r = 0, c = 0;
        vector < pair<int, int>> i1;
        findOne(grid, r, c);
        gatherIsland(grid, r, c, i1);
        
        // find 2nd island
        vector < pair<int, int>> i2;
        findOne(grid, r, c);
        gatherIsland(grid, r, c, i2);


        int ans = INT_MAX;
        for (auto& it : i1) {
            for (auto& jt : i2) {
                int dist = abs(it.first - jt.first) + abs(it.second - jt.second);
                ans = min(ans, dist);
            }
        }

        return ans - 1;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> grid = {{0, 1, 0}, {0, 0, 0}, {0, 0, 1}};

    cout << sol.shortestBridge(grid);

    cin >> c;
}