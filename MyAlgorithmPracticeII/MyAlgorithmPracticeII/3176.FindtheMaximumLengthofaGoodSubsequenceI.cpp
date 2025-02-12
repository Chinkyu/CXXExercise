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
    int maximumLength(vector<int>& A, int k) {
        vector<unordered_map<int, int>> dp(k + 1);
        vector<int> res(k + 1);
        for (int a : A) {
            for (int i = k; i >= 0; --i) {
                dp[i][a] = max(dp[i][a] + 1, (i > 0 ? res[i - 1] + 1 : 0));
                res[i] = max(res[i], dp[i][a]);
            }
        }
        return res[k];
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