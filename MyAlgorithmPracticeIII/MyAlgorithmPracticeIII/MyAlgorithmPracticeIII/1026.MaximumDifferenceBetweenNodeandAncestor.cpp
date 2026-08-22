// ok : maintain  min and max

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

class Solution {
public:
    int t_max = 0;
    void traverse(TreeNode* root, int pmin, int pmax) {
        if (root == nullptr) return;

        pmin = min(pmin, root->val);
        pmax = max(pmax, root->val);

        t_max = max(t_max, abs(pmin - root->val));
        t_max = max(t_max, abs(pmax - root->val));

        if (root->left != nullptr) {
            traverse(root->left, pmin, pmax);
        }

        if (root->right != nullptr) {
            traverse(root->right, pmin, pmax);
        }
    }

    int maxAncestorDiff(TreeNode* root) {
        int pmin = root->val;
        int pmax = root->val;

        t_max = 0;
        traverse(root, pmin, pmax);
        
        return t_max;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> segments = { {1, 4, 5}, {4, 7, 7}, {1, 7, 9} };

    vector<vector<long long>> ans = sol.splitPainting(segments);
    for (auto& it : ans) {
        cout << it[0] << " " << it[1] << " " << it[2] << endl;
    }

    cin >> c;
}
