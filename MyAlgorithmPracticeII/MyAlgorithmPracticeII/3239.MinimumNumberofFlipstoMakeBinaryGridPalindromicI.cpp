// ok : go straight forward 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
    int minFlips(vector<vector<int>>& grid) {
        int l = grid.size();
        int m = grid[0].size();

        // for column
        int cnt = 0;
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                if (grid[i][j] != grid[i][m - j - 1]) cnt++;
            }
        }

        // for row
        int cnt2 = 0;
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < l / 2; ++i) {
                if (grid[i][j] != grid[l - i - 1][j]) cnt2++;
            }
        }

        return min(cnt, cnt2);
    }
};

int main() {
    Solution sol;
    char c;

    vector<vector<int>> grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    cout << sol.minFlips(grid);

    cin >> c;
}
