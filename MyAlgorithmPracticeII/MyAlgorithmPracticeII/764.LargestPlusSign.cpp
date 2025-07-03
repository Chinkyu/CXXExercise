// see anser : in eash point check reaches... 
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

// check reach.... 
int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {

    vector<vector<int>> mat(n, vector<int>(n, 1));
    for (auto it : mines)
    {
        int x = it[0];
        int y = it[1];
        mat[x][y] = 0;
    }

    vector<vector<int>> lef, rig, top, bot;
    lef = rig = top = bot = mat;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = n - i - 1;
            int y = n - j - 1;
            if ((i > 0) && top[i][j]) top[i][j] += top[i - 1][j];
            if ((j > 0) && lef[i][j]) lef[i][j] += lef[i][j - 1];
            if ((x < n - 1) && bot[x][y]) bot[x][y] += bot[x + 1][y];
            if ((y < n - 1) && rig[x][y]) rig[x][y] += rig[x][y + 1];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, min({ lef[i][j], rig[i][j], top[i][j], bot[i][j] }));

    return ans;
}

// 다해보기... timeout 
class _Solution {
public:
    bool doesCross(map<vector<int>, bool>& m, int ix, int jx, int size) {
        
        for (int i = 0; i < size; ++i) {
            if (m.find({ix + (size / 2), jx + i}) != m.end()) return false;
            if (m.find({ ix + i , jx + (size / 2) }) != m.end()) return false;
        }
        return true;
    }


    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        // 다해보면 되지..
        map<vector<int>, bool> m;
        for (auto& it : mines) {
            m[{it[0], it[1]}] = true;
        }

        int ans = 0;
        for (int i = 3; i <= n; i += 2) {
            bool find = false;
            for (int j = 0; j + i <= n; j++) {
                for (int k = 0; k + i <= n; k++) {
                    if (doesCross(m, j, k, i)) {
                        ans = i / 2 + 1;
                        find = true;
                        break;
                    }
                }
                if (find == true) break;
            }
        }

        if (ans == 0 && m.size() != n * n) ans = 1;

        return ans;

    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> mines = { {4, 2} };

    cout << sol.orderOfLargestPlusSign(5, mines);

    cin >> c;
}