// ����� : 

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
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if (i + 1 == grid.size() && j + 1 == grid[0].size()) return true;
        if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return false;
        grid[i][j] = 0;
        return dfs(grid, i + 1, j) || dfs(grid, i, j + 1);
    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if (dfs(grid, 0, 0) == false) return true;
        grid[0][0] = 1;
        return !dfs(grid, 0, 0);
    }
};

int main() {
    char c;
    Solution sol;


    //cout << sol.maximumRemovals(s, p, removable);

    cin >> c;
}