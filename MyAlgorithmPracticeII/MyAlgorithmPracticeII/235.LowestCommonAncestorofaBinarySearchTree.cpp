// easy : if find logic

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* c = root;
        while (true) {

            if ((p->val <= c->val && c->val <= q->val) ||
                (q->val <= c->val && c->val <= p->val)) {
                return c;
            }
            
            if (p->val < c->val) {
                c = c->left;
            }
            else {
                c = c->right;
            }
        }
        
        return nullptr;
    }
};

int main() {
    char c;
    Solution sol;
    vector<string> nums = { "102","473","251","814" };
    vector<vector<int>> queries = { {1,1}, {2,3}, {4, 2}, {1,2} };

    vector<int> ans = sol.smallestTrimmedNumbers(nums, queries);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}