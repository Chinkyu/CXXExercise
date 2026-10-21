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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* p = root;

        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }

        do {
            if (val < p->val) {
                if (p->left == nullptr) {
                    p->left = new TreeNode(val);
                    return root;
                }
                else {
                    p = p->left;
                }
            }
            else {
                if (p->right == nullptr) {
                    p->right = new TreeNode(val);
                    return root;
                }
                else {
                    p = p->right;
                }
            }
        } while (true);

        return root;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 61,23,38,23,56,40,82,56,82,82,82,70,8,69,8,7,19,14,58,42,82,10,82,78,15,82 };

    cout << sol.countSubarrays(nums, 2);

    cin >> c;
}
