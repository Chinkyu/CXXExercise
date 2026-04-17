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
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        dp[0] = 1;
        int md = 1e9 + 7;
        for (int i = min(zero, one); i <= high; i++) {
            if (i >= zero) {
                dp[i] = (dp[i] + dp[i - zero]) % md;
            }
            if (i >= one) {
                dp[i] = (dp[i] + dp[i - one]) % md;
            }

        }
        int sum = 0;
        for (int i = low; i <= high; i++) {
            sum = (sum + dp[i]) % md;
        }
        return sum;
    }
};
int main() {
    char c;
    Solution sol;
    //vector<vector<int>> buildings = {{1, 3}, {3, 2}, {3, 3}, {3, 5}, {5, 3}};
    vector<vector<int>> buildings = { {2, 4}, {1, 2}, {3, 1}, {1, 4}, {2, 3}, {3, 3}, {2, 2}, {1, 3} };

    cout << sol.countCoveredBuildings(4, buildings);

    cin >> c;
}
