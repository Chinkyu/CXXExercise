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

    void traverse(TreeNode* root, int tmax) {

        if (tmax <= root->val) {
            ans++;
        }


        tmax = max(tmax, root->val);
        if (root->left != nullptr) {
            traverse(root->left, tmax);
        }

        if (root->right != nullptr) {
            traverse(root->right, tmax);
        }
    }

    int goodNodes(TreeNode* root) {
        ans = 0;

        traverse(root, INT_MIN);

        return ans;

    }
};

int main() {
    char c;
    Solution sol;


    vector<string> ans = sol.simplifiedFractions(4);

    for (auto& it : ans) {
        cout << it << " ";
    }


    cin >> c;
}
