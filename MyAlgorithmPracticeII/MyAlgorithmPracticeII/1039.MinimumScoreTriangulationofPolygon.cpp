// see answer : dp
// 일단 다해보는 Concept 인데...  memoization 을 넣은거지... 되나???
// 생각하기 힘든 솔루션이다..
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

    int solve(vector<int>& values, int i, int j, vector<vector<int>>& dp)
    {
        if (i + 1 == j) return 0;

        if (dp[i][j] != 0) return dp[i][j];

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            int temp = values[i] * values[j] * values[k] + solve(values, i, k, dp) + solve(values, k, j, dp);
            ans = min(temp, ans);
            dp[i][j] = ans;
        }

        return ans;
    }

    int minScoreTriangulation(vector<int>& values) {

        int n = values.size() - 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        return solve(values, 0, n, dp);
    }
};

class _Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int l = values.size();
        vector<int> prod;
        for (int i = 0; i < l-1; ++i) {
            prod.push_back(values[i] * values[i + 1]);
        }
        prod.push_back(values[l - 1] * values[0]);


        long long sum = 0;
        for (auto &it : prod) {
            sum += it;
        }

        long long t_min = LLONG_MAX;
        for (int i = 0; i < l; ++i) {
            long long score = (sum - prod[i]) * values[i];
            t_min = min(t_min, score);
        }

        return t_min;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> values = { 1,3,1,4,1,5 };

    cout << sol.minScoreTriangulation(values);

    cin >> c;
}