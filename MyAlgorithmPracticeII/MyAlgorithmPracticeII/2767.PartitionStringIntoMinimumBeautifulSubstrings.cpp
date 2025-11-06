// see answer : dp
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
    int minimumBeautifulSubstrings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') continue;
            for (int j = i, cur = 0; j < n; j++) {
                cur = cur * 2 + s[j] - '0';
                if (15625 % cur == 0)
                    dp[j + 1] = min(dp[j + 1], dp[i] + 1);
            }
        }
        return dp[n] > n ? -1 : dp[n];
    }
};

int main() {
    Solution sol;
    char c;
    vector<string> creators = { "alice", "bob", "alice", "chris" };
    vector<string> ids = { "one", "two", "three", "four" };
    vector<int> views = { 5, 10, 5, 4 };

    vector<vector<string>> ans = sol.mostPopularCreator(creators, ids, views);

    for (auto it : ans) {
        cout << it[0] << " " << it[1] << endl;
    }


    cin >> c;
}
