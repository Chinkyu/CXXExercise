// ok : 
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans = 0;
    pair<int, int> traverse(TreeNode* root) {

        int cnt = 0;
        int sum = 0;

        if (root->left != nullptr) {
            pair<int, int> la = traverse(root->left);
            cnt += la.first;
            sum += la.second;
        }
        if (root->right != nullptr) {
            pair<int, int> la = traverse(root->right);
            cnt += la.first;
            sum += la.second;
        }

        cnt++;
        sum += root->val;

        if (sum / cnt == root->val) ans++;
        return make_pair(cnt, sum);
    }

    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        traverse(root);
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 4, 3, 1, 6 };
    vector<vector<int>> queries = { {0, 2}, {2, 3} };

    vector<bool> ans = sol.isArraySpecial(nums, queries);

    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
