// timeout -> see answer.... 
// 
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
    vector<int> DIR = { 0, 1, 0, -1, 0 };
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (mat[r][c] == 0) q.emplace(r, c);
                else mat[r][c] = -1; // Marked as not processed yet!

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            //auto [r, c] = q.front(); 
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + DIR[i], nc = c + DIR[i + 1];
                if (nr < 0 || nr == m || nc < 0 || nc == n || mat[nr][nc] != -1) continue;
                mat[nr][nc] = mat[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
        return mat;
    }
};



// 중간값을 사용하면 Wrong answer...    -> 쉬운 방법이 있을것 같음... 
// timeout as well
class __Solution {
public:
    int shortestPath(vector<vector<int>>& mat, vector<vector<int>>& v,  int r, int c) {
        int rl = mat.size(), cl = mat[0].size();
        queue<vector<int>> q;
        q.push({ r, c });
        int length = 0;

        while (!q.empty()) {
            length++;
            queue<vector<int>> tq;


            while (!q.empty()) {
                vector<int> t = q.front();
                r = t[0];
                c = t[1];
                q.pop();
                v[r][c] = 1;

                int min_dist = INT_MAX;
                // left
                if (0 <= c - 1 && v[r][c - 1] != 1) {
                    if (mat[r][c - 1] == -1) {
                        tq.push({ r, c - 1 });
                        //v[r][c - 1] = 1;
                    }
                    else {
                        min_dist = min(min_dist, mat[r][c - 1]);
                    }
                }

                // right
                if (c + 1 < cl && v[r][c + 1] != 1) {
                    if (mat[r][c + 1] == -1) {
                        tq.push({ r, c + 1 });
                        //v[r][c + 1] = 1;
                    }
                    else {
                        min_dist = min(min_dist, mat[r][c + 1]);
                    }
                }

                // up
                if (0 <= r - 1 && v[r-1][c] != 1) {
                    if (mat[r-1][c] == -1) {
                        tq.push({ r-1, c});
                        //v[r-1][c] = 1;
                    }
                    else {
                        min_dist = min(min_dist, mat[r-1][c]);
                    }
                }

                // down
                if (r + 1 < rl && v[r+1][c] != 1) {
                    if (mat[r + 1][c] == -1) {
                        tq.push({ r + 1, c });
                        //v[r+1][c] = 1;
                    }
                    else {
                        min_dist = min(min_dist, mat[r + 1][c]);
                    }
                }

                if (min_dist != INT_MAX) {
                    return min_dist + length;
                }

            }
            q = tq;

        }

        return -1;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rl = mat.size(), cl = mat[0].size();

        vector<vector<int>> ans = mat;
        for (int i = 0; i < rl; ++i) {
            for (int j = 0; j < cl; ++j) {
                if (mat[i][j] == 1) ans[i][j] = -1;
            }
        }

        for (int i = 0; i < rl; ++i) {
            for (int j = 0; j < cl; ++j) {
                vector<vector<int>> v(rl, vector<int>(cl, 0));
                if (ans[i][j] == -1) {
                    ans[i][j] = shortestPath(ans, v, i, j);
                }
            }
        }

        vector<vector<int>> ansbu = mat;
        for (int i = 0; i < rl; ++i) {
            for (int j = 0; j < cl; ++j) {
                if (mat[i][j] == 1) ansbu[i][j] = -1;
            }
        }

        for (int i = rl - 1; i >= 0; --i) {
            for (int j = cl -1; j >= 0; --j) {
                vector<vector<int>> v(rl, vector<int>(cl, 0));
                if (ansbu[i][j] == -1) {
                    ansbu[i][j] = shortestPath(ansbu, v, i, j);
                }
            }
        }

        // mrege with lower value
        for (int i = 0; i < rl; ++i) {
            for (int j = 0; j < cl; ++j) {
                ans[i][j] = (ans[i][j] < ansbu[i][j]) ? ans[i][j] : ansbu[i][j];
            }
        }

        return ans;
    }

};

#if 0 

// 모두 끝까지 가면 Timeout... 
class __Solution {
public:
    int shortestPath(vector<vector<int>>& mat, vector<vector<int>>& v, int r, int c) {
        int rl = mat.size(), cl = mat[0].size();
        queue<vector<int>> q;
        q.push({ r, c });
        int length = 0;

        while (!q.empty()) {
            length++;
            queue<vector<int>> tq;


            while (!q.empty()) {
                vector<int> t = q.front();
                r = t[0];
                c = t[1];
                q.pop();
                v[r][c] = 1;


                int min_dist = INT_MAX;
                // left
                if (0 <= c - 1 && v[r][c - 1] != 1) {
                    if (mat[r][c - 1] != 0) {
                        tq.push({ r, c - 1 });
                        //v[r][c - 1] = 1;
                    }
                    else {
                        min_dist = 0;// min(min_dist, mat[r][c - 1]);
                    }
                }

                // right
                if (c + 1 < cl && v[r][c + 1] != 1) {
                    if (mat[r][c + 1] != 0) {
                        tq.push({ r, c + 1 });
                        //v[r][c + 1] = 1;
                    }
                    else {
                        min_dist = 0; // min(min_dist, mat[r][c + 1]);
                    }
                }

                // up
                if (0 <= r - 1 && v[r - 1][c] != 1) {
                    if (mat[r - 1][c] != 0) {
                        tq.push({ r - 1, c });
                        //v[r-1][c] = 1;
                    }
                    else {
                        min_dist = 0; // min(min_dist, mat[r - 1][c]);
                    }
                }

                // down
                if (r + 1 < rl && v[r + 1][c] != 1) {
                    if (mat[r + 1][c] != 0) {
                        tq.push({ r + 1, c });
                        //v[r+1][c] = 1;
                    }
                    else {
                        min_dist = 0; // min(min_dist, mat[r + 1][c]);
                    }
                }

                if (min_dist != INT_MAX) {
                    return min_dist + length;
                }

            }
            q = tq;

        }

        return -1;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rl = mat.size(), cl = mat[0].size();

        vector<vector<int>> ans = mat;
        for (int i = 0; i < rl; ++i) {
            for (int j = 0; j < cl; ++j) {
                if (mat[i][j] == 1) ans[i][j] = -1;
            }
        }

        for (int i = 0; i < rl; ++i) {
            for (int j = 0; j < cl; ++j) {
                vector<vector<int>> v(rl, vector<int>(cl, 0));
                if (ans[i][j] == -1) {
                    ans[i][j] = shortestPath(ans, v, i, j);
                }
            }
        }

        return ans;

    }

};
#endif

int main() {
    char c;
    Solution sol;
    vector<vector<int>> mat =
        //{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
        {{1, 1, 0, 0, 1, 0, 0, 1, 1, 0}, {1, 0, 0, 1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 1, 0, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 0, 0, 1, 1, 1}, {0, 1, 0, 1, 1, 0, 1, 1, 1, 1}, {1, 1, 1, 0, 1, 0, 1, 1, 1, 1}};

    vector<vector<int>>  ans = sol.updateMatrix(mat);

    for (auto& it : ans) {
        for (auto& jt : it) {
            cout << jt << " ";
        }
        cout << endl;
    }


    cin >> c;
}
