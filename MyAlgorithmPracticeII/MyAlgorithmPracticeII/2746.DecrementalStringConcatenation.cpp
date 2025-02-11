// see answer :  DP

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
    int dp[1000][26][26];
    int dfs(vector<string>& v, int start, int end, int i) {
        if (i >= v.size()) return 0;
        if (dp[i][start][end] != -1) return dp[i][start][end];
        int ans = 1e9;
        ans = min(ans, (int)v[i].size() - (end + 'a' == v[i][0]) + dfs(v, start, v[i].back() - 'a', i + 1));
        ans = min(ans, (int)v[i].size() - (start + 'a' == v[i].back()) + dfs(v, v[i][0] - 'a', end, i + 1));
        return dp[i][start][end] = ans;
    }

    int minimizeConcatenatedLength(vector<string>& v) {
        memset(dp, -1, sizeof(dp));
        return v[0].size() + dfs(v, v[0][0] - 'a', v[0].back() - 'a', 1);
    }
};

// timeout
class Solution {
public:

    int min_len = INT_MAX;

    string join(string& l, string& r) {
        string tl = l;
        if (tl.back() == r[0]) {
            tl.pop_back();
        }

        return tl + r;
    }


    void traverse(vector<string>& words, int idx, string s) {

        if (s.size() >= min_len) return;

        if (idx >= words.size()) {
            min_len = min(min_len, (int)s.size());
            return;
        }


        string lr = join(s, words[idx]);
        string rl = join(words[idx], s);

        traverse(words, idx + 1, rl);
        traverse(words, idx + 1, lr);

#if 0
        if (lr.size() > rl.size()) {
            traverse(words, idx + 1, rl);
        }
        else if (lr.size() < rl.size()) {
            traverse(words, idx + 1, lr);
        }
        else {
            traverse(words, idx + 1, rl);
            traverse(words, idx + 1, lr);
        }
#endif
    }


    int minimizeConcatenatedLength(vector<string>& words) {
        min_len = INT_MAX;
        traverse(words, 1, words[0]);

        return min_len;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<string> words = { "aa","ab","bc" };
    vector<string> words = { "aaa","c","aba" };

    cout << sol.minimizeConcatenatedLength(words);

    cin >> c;
}