// see answer : checking rotation make more complex
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
    int minFlips(string s) {
        // Characteristic function
        auto I = [](char ch, int x) -> int { return ch - '0' == x; };

        int n = s.size();
        vector<vector<int>> pre(n, vector<int>(2));
        // Note the boundary case when i=0
        for (int i = 0; i < n; ++i) {
            pre[i][0] = (i == 0 ? 0 : pre[i - 1][1]) + I(s[i], 1);
            pre[i][1] = (i == 0 ? 0 : pre[i - 1][0]) + I(s[i], 0);
        }

        int ans = min(pre[n - 1][0], pre[n - 1][1]);
        if (n % 2 == 1) {
            // If n is an odd number, it is also necessary to calculate suf
            vector<vector<int>> suf(n, vector<int>(2));
            // Note the boundary case when i = n - 1
            for (int i = n - 1; i >= 0; --i) {
                suf[i][0] = (i == n - 1 ? 0 : suf[i + 1][1]) + I(s[i], 1);
                suf[i][1] = (i == n - 1 ? 0 : suf[i + 1][0]) + I(s[i], 0);
            }
            for (int i = 0; i + 1 < n; ++i) {
                ans = min(ans, pre[i][0] + suf[i + 1][0]);
                ans = min(ans, pre[i][1] + suf[i + 1][1]);
            }
        }

        return ans;
    }
};

//:: ckkang :  rotation not checked
class _Solution {
public:
    int minFlips(string s) {
        int l = s.size();

        // check start 0101 mismach
        int m1 = 0;
        for (int i = 0; i < l; ++i) {
            if (i % 2 == 0 && s[i] != '0') {
                m1++;
            }

            if (i % 2 == 1 && s[i] != '1') {
                m1++;
            }
        }

        // check start 1010 mismatch
        int m2 = 0;
        for (int i = 0; i < l; ++i) {
            if (i % 2 == 0 && s[i] != '1') {
                m2++;
            }

            if (i % 2 == 1 && s[i] != '0') {
                m2++;
            }
        }

        return min(m1, m2);

    }
};

int main() {
    char c;
    Solution sol;

    string s = "111000";

    cout << sol.minFlips(s);

    cin >> c;
}
