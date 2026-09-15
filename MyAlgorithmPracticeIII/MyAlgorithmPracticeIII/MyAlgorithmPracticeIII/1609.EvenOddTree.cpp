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
    bool isEvenOddTree(TreeNode* root) {

        vector<TreeNode*> v, tv;
        v.push_back(root);
        int level = 0;

        while (v.size() != 0) {
            tv.clear();

            int c = -1;
            for (auto& it : v) {

                if (level % 2 == 0) {   // odd and increasing order

                    if (it->val % 2 != 1) {  // if not odd
                        return false;
                    }


                    if (c == -1) {   // not increasing
                        c = it->val;
                    }
                    else  if (it->val <= c) {
                        return false;
                    }

                }
                else {  // even and increasing order
                    if (it->val % 2 != 0) { // if not even
                        return false;
                    }

                    if (c == -1) {
                        c = it->val;
                    }
                    else  if (it->val >= c) { // not decreasing
                        return false;
                    }

                }



                if (it->left != nullptr) {
                    tv.push_back(it->left);
                }

                if (it->right != nullptr) {
                    tv.push_back(it->right);
                }

                c = it->val;
            }

            v = tv;
            level++;

        }

        return true;

    }
};

int main() {
    char c;
    Solution sol;

    string s = "1101";
    cout << sol.numSteps(s);

    cin >> c;
}
