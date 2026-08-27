// ok... May need to actual find 
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
#include <numeric>

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

class FindElements {
public:
    TreeNode* r;
    unordered_map<int, int> m;

    void makeTree(TreeNode* root) {
        if (root->left != nullptr) {
            root->left->val = root->val * 2 + 1;
            m[root->val * 2 + 1] = 1;
            makeTree(root->left);
        }

        if (root->right != nullptr) {
            root->right->val = root->val * 2 + 2;
            m[root->val * 2 + 2] = 1;
            makeTree(root->right);
        }
    }


    FindElements(TreeNode* root) {
        m.clear();

        r = root;
        root->val = 0;
        m[0] = 1;
        makeTree(root);
    }

#if 0
    bool traverse(TreeNode* r, int target) {

        if (r->val == target) {
            return true;
        }
        else if (r->val < target) {
            if (r->right != nullptr) {
                return traverse(r->right, target);
            }
            else {
                return false;
            }
        }
        else {  // r->val > target
            if (r->left != nullptr) {
                return traverse(r->left, target);
            }
            else {
                return false;
            }

        }

        return false;
    }
#endif

    bool find(int target) {
        //return traverse(r, target);
        if (m.find(target) != m.end()) {
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main() {
    char c;

    TreeNode* root = new TreeNode(-1);
    root -> left = new TreeNode(-1);
    root->left->left = new TreeNode(-1);
    root->left->right = new TreeNode(-1);
    root-> right = new TreeNode(-1);


    FindElements sol(root);

    cout << sol.find(1);

    cin >> c;
}
