// 문제가 이상한것 같음... 
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

    TreeNode* traverse(TreeNode* root, int accu, int limit) {
        if (root->left != nullptr) {
            root->left = traverse(root->left, accu + root->val, limit);
        }

        if (root->right != nullptr) {
            root->right = traverse(root->right, accu + root->val, limit);
        }

        if (root->left == nullptr && root->right == nullptr) {
            if (accu + root->val < limit) {
                delete root;
                return nullptr;
            }
        }

        return root;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {

        return traverse(root, 0, limit);

    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums{ 5,2,7,9,16 };
    cout << sol.longestSubarray(nums);

    cin >> c;
}
