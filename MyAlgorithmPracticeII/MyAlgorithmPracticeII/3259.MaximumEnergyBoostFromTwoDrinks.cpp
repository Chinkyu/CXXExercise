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
#define ll long long
    vector<vector<ll>> dp;
    ll f(vector<int>& A, vector<int>& B, int i, int curr) {
        if (i >= A.size()) return 0;
        if (dp[i][curr] != -1) return dp[i][curr];

        ll ans = 0;
        if (curr)
            ans = max(A[i] + f(A, B, i + 1, curr), f(A, B, i + 1, curr ^ 1));

        else
            ans = max(B[i] + f(A, B, i + 1, curr), f(A, B, i + 1, curr ^ 1));

        return dp[i][curr] = ans;
    }

    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
        int n = A.size();
        dp.clear();
        dp.resize(n, vector<ll>(2, -1));
        return max(f(A, B, 0, 1), f(A, B, 0, 0));
    }
};

int main() {
    Solution sol;
    char c;

    sol.combine(4, 2);

    cin >> c;
}
