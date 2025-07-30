// saw anser : dp

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
#include <cmath>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<int> dp(n + 1, 0);

        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j - 1] + s2[j - 1];
        }

        for (int i = 1; i <= m; i++) {
            int prev = dp[0];
            dp[0] += s1[i - 1];

            for (int j = 1; j <= n; j++) {
                int temp = dp[j];

                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = prev;
                }
                else {
                    dp[j] = min(dp[j] + s1[i - 1], dp[j - 1] + s2[j - 1]);
                }

                prev = temp;
            }
        }

        return dp[n];
    }
};


int main() {
    char c;
    Solution sol;

    //string num1 = "9", num2 = "99";

    vector<int> ans = sol.closestDivisors(999);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}