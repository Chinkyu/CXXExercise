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
    vector<int> largestValues(TreeNode* root) {

        vector<TreeNode*> v, tv;
        vector<int> ans;

        if (root == nullptr) return ans;

        v.push_back(root);

        while (v.size() != 0) {
            tv.clear();

            int t_max = INT_MIN;
            for (auto &it : v) {
                t_max = max(t_max, it->val);

                if (it->left != nullptr) {
                    tv.push_back(it->left);
                }

                if (it->right != nullptr) {
                    tv.push_back(it->right);
                }
            }

            ans.push_back(t_max);
            v = tv;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "1101";
    cout << sol.numSteps(s);

    cin >> c;
}
