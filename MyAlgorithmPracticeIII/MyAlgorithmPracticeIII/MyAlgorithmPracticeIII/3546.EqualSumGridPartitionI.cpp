// ok : using accumulation array 
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
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rl = grid.size(), cl = grid[0].size();
        vector<vector<long long>> c(rl + 1, vector<long long>(cl + 1, 0));

        for (int i = 1; i <= rl; ++i) {
            for (int j = 1; j <= cl; ++j) {
                c[i][j] = c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }

        if (c[rl][cl] % 2 == 1) return false;
        long long target = c[rl][cl] / 2;

        // check row
        for(int i = 1; i < rl; ++i) {
            if (c[i][cl] == target) return true;
        }

        // check column
        for (int j = 1; j < cl; ++j) {
            if (c[rl][j] == target) return true;
        }

        return false;

    }
};

int main() {
    char c;
    Solution sol;
    //vector<vector<int>> grid = { {1, 4},{2, 3} };
    //vector<vector<int>> grid = { {1, 3},{2, 4} };
    vector<vector<int>> grid = { {1, 1, 1} };

    cout << sol.canPartitionGrid(grid);

    cin >> c;
}
