// 답봤음

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
    long long gridGame(vector<vector<int>>& grid) {
        long long top = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            top += grid[0][i];
        }

        long long bottom = 0, res = LLONG_MAX;
        for (int i = 0; i < grid[0].size(); i++) {
            top -= grid[0][i]; // First robot picks from the top row 
            res = min(res, max(top, bottom)); // Minimize the maximum score for the second robot
            bottom += grid[1][i]; // Second robot picks from the bottom row 🤖
        }
        return res;
    }
};

int main() {
    char c;
    Solution sol;

    //    string colors = "abaac";
    //    vector<int> needTime = { 1, 2, 3, 4, 5 };
    string colors = "aabaa";
    vector<int> needTime = { 1, 2, 3, 4, 1 };


    cout << sol.minCost(colors, needTime);

    cin >> c;
}