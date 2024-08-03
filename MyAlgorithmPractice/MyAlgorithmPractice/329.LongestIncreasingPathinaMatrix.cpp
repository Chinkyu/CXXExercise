// ¥‰∫√¿Ω : dp memoization 
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
    bool isSafe(int i, int j, int m, int n,
        vector<vector<int>>& matrix, int prev) {
        return i >= 0 && j >= 0 && i < m && j < n &&
            matrix[i][j] > prev;
    }
    int solve(int i, int j, int m, int n, vector<vector<int>>& matrix,
        int prev, vector<vector<int>>& dp) {

        int maxi = 1;


        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        // Right
        int ni = i + 0;
        int nj = j + 1;
        if (isSafe(ni, nj, m, n, matrix, prev)) {

            maxi = max(maxi, 1 + solve(ni, nj, m, n, matrix, matrix[ni][nj], dp));

        }

        // Down
        ni = i + 1;
        nj = j + 0;
        if (isSafe(ni, nj, m, n, matrix, prev)) {

            maxi = max(maxi, 1 + solve(ni, nj, m, n, matrix, matrix[ni][nj], dp));

        }

        // Left
        ni = i + 0;
        nj = j - 1;
        if (isSafe(ni, nj, m, n, matrix, prev)) {

            maxi = max(maxi, 1 + solve(ni, nj, m, n, matrix, matrix[ni][nj], dp));

        }

        // Up
        ni = i - 1;
        nj = j + 0;
        if (isSafe(ni, nj, m, n, matrix, prev)) {

            maxi = max(maxi, 1 + solve(ni, nj, m, n, matrix, matrix[ni][nj], dp));

        }




        return dp[i][j] = maxi;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, solve(i, j, m, n, matrix, matrix[i][j], dp));
            }
        }
        return ans;

    }
};

int main() {
    Codec sol;
    char c;

    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->right->left = new TreeNode(4);
    r->right->right = new TreeNode(5);


    string ans = sol.serialize(r);
    cout << ans;

    TreeNode* root = sol.deserialize(ans);

    cin >> c;
}
