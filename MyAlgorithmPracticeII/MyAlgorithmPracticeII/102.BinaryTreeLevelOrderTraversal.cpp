// easy
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
;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if (root == nullptr) return ans;

        q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> tq;
            vector<int> level;
            while (!q.empty()) {
                TreeNode *p = q.front();
                q.pop();
                if (p->left != nullptr) tq.push(p->left);
                if (p->right != nullptr) tq.push(p->right);
                level.push_back(p->val);
            }
            ans.push_back(level);
            q = tq;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    char c;

    sol.combine(4, 2);

    cin >> c;
}
