// see answer dp 
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


// memory limit exceed
class _Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> v(m, vector<vector<int>>(n, vector<int>()));  // visit vector

        vector<vector<int>> l;

        l.push_back({ 0, 0 });
        v[0][0].push_back(grid[0][0]);
        do {
            vector<vector<int>> tl;
            for (auto& it : l) {
                int r = it[0];
                int c = it[1];

                // right
                int tr = it[0];
                int tc = it[1] + 1;

                if (tr < m && tc < n) {
                    for (int i = 0; i < v[r][c].size(); ++i) {
                        int t = v[r][c][i] ^ grid[tr][tc];
                        v[tr][tc].push_back(t);
                    }

                    tl.push_back({ tr, tc });;
                }

                // down
                tr = it[0] + 1;
                tc = it[1];

                if (tr < m && tc < n) {
                    for (int i = 0; i < v[r][c].size(); ++i) {
                        int t = v[r][c][i] ^ grid[tr][tc];
                        v[tr][tc].push_back(t);
                    }

                    tl.push_back({ tr, tc });;
                }
            }

            l = tl;
        } while (l.size() > 0);

        int ans = INT_MAX; 
        for (int i = 0; i < v[m - 1][n - 1].size(); ++i) {
            ans = min(ans, v[m - 1][n - 1][i]);
        }


        return ans;
    }
};

// time limit 
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //vector<vector<vector<int>>> v(m, vector<vector<int>>(n, vector<int>()));  // visit vector

        //vector<vector<int>> l;
        map<pair<int, int>, vector<int>> l;

        l[make_pair(0, 0)].push_back(grid[0][0]);
        int r, c;
        do {
            map<pair<int, int>, vector<int>> tl;
            for (auto& it : l) {
                r = it.first.first;
                c = it.first.second;

                // right
                int tr = r;
                int tc = c + 1;

                if (tr < m && tc < n) {
                    for (int i = 0; i < l[make_pair(r, c)].size(); ++i) {
                        int t = l[make_pair(r, c)][i] ^ grid[tr][tc];
                        tl[make_pair(tr, tc)].push_back(t);
                    }
                }

                // down
                tr = r + 1;
                tc = c;

                if (tr < m && tc < n) {
                    for (int i = 0; i < l[make_pair(r, c)].size(); ++i) {
                        int t = l[make_pair(r, c)][i] ^ grid[tr][tc];
                        tl[make_pair(tr, tc)].push_back(t);
                    }
                }
            }

            if (r == m - 1 && c == n - 1) {
                break; // end 
            }

            l = tl;
        } while (r != m - 1 || c != n - 1);  // not last 

        int ans = INT_MAX;
        for (int i = 0; i < l[make_pair(m - 1, n - 1)].size(); ++i) {
            ans = min(ans, l[make_pair(m - 1, n - 1)][i]);
        }


        return ans;
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<bool>>> vis(
            n, vector<vector<bool>>(m, vector<bool>(1024, false))
        );

        queue<tuple<int, int, int>> q;

        q.push({ 0,0,grid[0][0] });
        vis[0][0][grid[0][0]] = true;

        while (!q.empty()) {
            auto [x, y, xr] = q.front();
            q.pop();

            // down
            if (x + 1 < n) {
                int nx = xr ^ grid[x + 1][y];
                if (!vis[x + 1][y][nx]) {
                    vis[x + 1][y][nx] = true;
                    q.push({ x + 1,y,nx });
                }
            }

            // right
            if (y + 1 < m) {
                int nx = xr ^ grid[x][y + 1];
                if (!vis[x][y + 1][nx]) {
                    vis[x][y + 1][nx] = true;
                    q.push({ x,y + 1,nx });
                }
            }
        }

        for (int i = 0; i < 1024; i++) {
            if (vis[n - 1][m - 1][i]) {
                return i;
            }
        }

        return 0;
    }
};


int main() {
    char c;
    Solution sol;

    //vector<vector<int>> grid = { {6, 7}, {5, 8} };
    //vector<vector<int>> grid = { {2, 7, 5} };
    vector<vector<int>> grid = { {26, 24, 3}, {2, 22, 17 } };

    cout << sol.minCost(grid);

    cin >> c;
}
