// ok : traverse

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
#include <random>

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == nullptr) {
            return ans;
        }

        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        level.push_back(root->val);
        ans.push_back(level);

        do {
            level.clear();
            queue<TreeNode*> tq;
            while (!q.empty()) {
                TreeNode* n = q.front();
                q.pop();
                if (n->left != nullptr) {
                    level.push_back(n->left->val);
                    tq.push(n->left);
                }
                if (n->right != nullptr) {
                    level.push_back(n->right->val);
                    tq.push(n->right);
                }
            }
            q = tq;
            if(level.size() > 0) ans.push_back(level);
        } while (q.size() > 0);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string text = "fwymvreuftzgrcrxczjacqovduqaiig";
    string pattern = "yy";

    cout << sol.maximumSubsequenceCount(text, pattern);


    cin >> c;
}
