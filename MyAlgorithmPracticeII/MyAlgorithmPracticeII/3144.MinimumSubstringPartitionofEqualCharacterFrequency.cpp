// ¥‰∫√¿Ω : dp

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
    int minimumSubstringsInPartition(const string& s) {
        vector<int> dp(s.size() + 1, s.size());
        dp.back() = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            int cnt[26] = {}, unique = 0, max_cnt = 0;
            for (int sz = 1; i + sz <= s.size(); ++sz) {
                unique += ++cnt[s[i + sz - 1] - 'a'] == 1;
                max_cnt = max(max_cnt, cnt[s[i + sz - 1] - 'a']);
                if (sz == unique * max_cnt)
                    dp[i] = min(dp[i], 1 + dp[i + sz]);
            }
        }
        return dp[0];
    }
};
int main() {
    char c;
    Solution sol;


    //cout << sol.maximumRemovals(s, p, removable);

    cin >> c;
}