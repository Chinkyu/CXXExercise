// easy : traverse and compare
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


class _Solution {
public:
    bool isValidBST(TreeNode* root) {

        bool ans = true;

        if (root->left != nullptr) {
            if (root->left->val >= root->val) {
                ans = false;
                return false;
            }

            ans = isValidBST(root->left);
        }
        if (ans == false) return false;

        if (root->right != nullptr) {
            if (root->val >= root->right->val) {
                ans = false;
                return false;
            }
            ans = isValidBST(root->right);
        }
        if (ans == false) return false;

        return true;
    }
};

class Solution {
public:
    vector<int> t;

    void traverse(TreeNode* root) {

        if (root->left != nullptr) {
            traverse(root->left);
        }

        t.push_back(root->val);

        if (root->right != nullptr) {
            traverse(root->right);
        }


    }


    bool isValidBST(TreeNode* root) {

        t.clear();

        traverse(root);

        set<int> s;
        for (auto& it : t) s.insert(it);

        vector<int> st = t;
        sort(st.begin(), st.end());

        if (s.size() != t.size()) return false;   // duplication

        if (t == st) {
            return true;
        }

        return false;
    }
};


int main() {
    char c;
    Solution sol;

    vector<int> nums = { 3, 1, 2 };
    cout << sol.uniqueXorTriplets(nums);

    cin >> c;
}
