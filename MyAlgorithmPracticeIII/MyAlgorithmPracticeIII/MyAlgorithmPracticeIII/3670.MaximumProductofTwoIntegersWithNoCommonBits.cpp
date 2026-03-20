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
#include <random>
#include <chrono>
#include <iterator>

using namespace std;

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int max_n = *max_element(begin(nums), end(nums));
        int msb = log2(max_n), max_mask = (1 << (msb + 1)) - 1;
        vector<int> dp(max_mask + 1);
        for (int x : nums)
            dp[x] = x;
        for (int b = 0; b <= msb; ++b)
            for (int mask = 0; mask < max_mask; ++mask)
                if (mask & (1 << b))
                    dp[mask] = max(dp[mask], dp[mask ^ (1 << b)]);
        long long ans = 0;
        for (int n : nums)
            ans = max(ans, 1LL * n * dp[max_mask ^ n]);
        return ans;
    }
};

// timeout 
class _Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long ans = 0;

        set<int> s;
        for (auto& it : nums) s.insert(it);

        vector<int> n;
        for (auto& it : s) n.push_back(it);

        int l = n.size();
        for (int i = 0; i < l; ++i) {
            for (int j = i + 1; j < l; ++j) {
                if ((n[i] & n[j]) == 0) {
                    ans = max(ans, (long long)n[i] * n[j]);
                }
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "LeetcodeHelpsMeLearn";
    vector<int> spaces = { 8, 13, 15 };

    cout << sol.addSpaces(s, spaces);

    cin >> c;
}
