//  see answer
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
#include <set>
#include <list>
#include <regex>
#include <memory>
#include <functional>

using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players;
        int n = scores.size();
        for (int i = 0; i < n; i++) {
            players.push_back({ ages[i], scores[i] });
        }
        sort(players.begin(), players.end(), greater<>());

        int ans = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            int score = players[i].second;
            dp[i] = score;
            for (int j = 0; j < i; j++) {
                if (players[j].second >= players[i].second) { // age of j is certainly >= i, so only important part to check 
                    //  before we add i and j in the same team is the score.
                    dp[i] = max(dp[i], dp[j] + score);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 10, 6, 5, 8 };

    vector<int> ans = sol.findLonely(nums);

    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}