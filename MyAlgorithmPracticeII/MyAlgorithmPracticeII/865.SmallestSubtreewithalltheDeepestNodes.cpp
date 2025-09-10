// Ok : verbose
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
    vector<vector<TreeNode*>> paths;
    int max_depth = 0;
    void traverse(TreeNode* p, vector<TreeNode*> path, int depth) {

        path.push_back(p);
        if (p->left == nullptr && p->right == nullptr) {

            if (depth > max_depth) {
                paths.clear();
                paths.push_back(path);
                max_depth = depth;
            }
            else if (depth == max_depth) {
                paths.push_back(path);
            }
            
            return;
        }

        if (p->left != nullptr) {            
            traverse(p->left, path, depth + 1);
        }

        if (p->right != nullptr) {
            traverse(p->right, path, depth + 1);
        }

    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        max_depth = 0;
        vector<TreeNode*> path;
        traverse(root, path, 1);

        if (paths.size() == 1) {
            return paths[0].back();
        }

        // find common path
        //TreeNode *ans = root;
        for (int i = 0; paths[0].size(); ++i) {
            TreeNode* p = paths[0][i];
            for (int j = 1; j < paths.size(); ++j) {
                if (p != paths[j][i]) {
                    // different
                    return paths[0][i - 1];
                }
            }
        }

        return nullptr;
    }
};

int main() {
    char c;
    Solution sol;
    
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode* p = sol.subtreeWithAllDeepest(root);

    cout << p->val;

    cin >> c;
}