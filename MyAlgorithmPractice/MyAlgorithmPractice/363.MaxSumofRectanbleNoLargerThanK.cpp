// ¥‰∫√¿Ω : prefix sum
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
    int maxSumSubmatrix(vector<vector<int>>& matrix, int tar) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>>dp(m + 1, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i + 1][j] = dp[i][j] + matrix[i][j];
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int l = i + 1; l <= m; l++) {
                for (int j = 0; j < n; j++) {
                    int val = 0;
                    for (int k = j; k < n; k++) {
                        val += dp[l][k] - dp[i][k];

                        if (val < tar) {
                            ans = max(ans, val);
                        }
                        else if (val == tar) {
                            return tar;
                        }
                    }
                }
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
