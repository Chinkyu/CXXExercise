// ok 
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
#include <chrono>
#include <iterator>

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
    TreeNode* n;
    void traverse(TreeNode* root) {

        if (root == nullptr) return;

        n->right = root;
        n->left = nullptr;
        n = n->right;

        TreeNode* l = root->left;
        TreeNode* r = root->right;
        if (l != nullptr) {
            traverse(l);
        }

        if (r != nullptr) {
            traverse(r);
        }

    }

    void flatten(TreeNode* root) {
        TreeNode* newroot = new TreeNode(0);
        n = newroot;
        traverse(root);

        root = n->right;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1, 0, 2 };
    // {1, 2, 0 };

    cout << sol.isIdealPermutation(nums);
    cin >> c;
}
