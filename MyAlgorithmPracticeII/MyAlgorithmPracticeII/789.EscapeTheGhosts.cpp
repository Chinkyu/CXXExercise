// Tricky.. : 직선 거리가 아니라 직각 거리가 맞다....   
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
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        //long long dt = pow(target[0], 2) + pow(target[1], 2);
        long long dt = abs(target[0]) + abs(target[1]);

        for (int i = 0; i < ghosts.size(); ++i) {
            long long dist = abs(target[0] - ghosts[i][0]) + abs(target[1] - ghosts[i][1]);
            if ( dt >= dist) return false;
        }

        return true;
    }
};



int main() {
    char c;
    Solution sol;
    //vector<vector<int>> ghosts = { { 1, 0}, {0, 3} };
    vector<vector<int>> ghosts = {{1, 8}, {-9, 0}, {-7, -6}, {4, 3}, {1, 3}};
    vector<int> target = { 6, -9 };
    cout << sol.escapeGhosts(ghosts, target);

    cin >> c;
}