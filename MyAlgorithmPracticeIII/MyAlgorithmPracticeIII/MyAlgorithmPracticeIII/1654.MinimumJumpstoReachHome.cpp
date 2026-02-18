// See answer : dp
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
#include <random>
#include <chrono>
#include <iterator>

using namespace std;

class Solution {
public:
    unordered_map<int, int> mp;
    int dp[6001][2];


    int helper(int i, bool back, int a, int b, int x) {
        if (i == x)
            return 0;
        if (i < 0 || i>6000 || back >= 2 || mp.find(i) != mp.end())
            return 1e9;
        if (dp[i][back] != -1)
            return dp[i][back];

        dp[i][back] = 1 + helper(i + a, 0, a, b, x); //go forward

        if (!back) //cannot go consecutively backwards more than 1
        {
            dp[i][back] = min(dp[i][back], helper(i - b, 1, a, b, x) + 1);

        }
        return dp[i][back];
    }


    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for (int i = 0; i < forbidden.size(); i++) {
            mp[forbidden[i]] = 1;
        }
        memset(dp, -1, sizeof(dp));
        int ans = helper(0, 0, a, b, x);
        if (ans > 1e9)
            return -1;
        return ans;
    }
};


int main() {
    char c;
    Solution sol;

    vector<vector<int>> edges = { {1, 0}, {1, 2}, {1, 3} };
    //"baeyh";

    vector<int> ans = sol.findMinHeightTrees(4, edges);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
