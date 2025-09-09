// saw answer :  longest common distance
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
    int minDistance(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcs = dp[m][n];
        return (m - lcs) + (n - lcs);
    }
};

int main() {
    char c;
    Solution sol;
    vector<string> keyName = { "daniel", "daniel", "daniel", "luis", "luis", "luis", "luis" };
    vector<string> keyTime = { "10:00", "10:40", "11:00", "09:00", "11:00", "13:00", "15:00" };

    vector<string> ans = sol.alertNames(keyName, keyTime);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}