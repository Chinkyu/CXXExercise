// ok : level order traverse
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


class _Solution {
public:

    vector<int> v;

    void traverse(TreeNode* root, int level) {

        if (root->left == nullptr && root->right == nullptr) {
            v.push_back(level);
            return;
        }

        if (root->left != nullptr) {
            traverse(root->left, level + 1);
        }

        if (root->right != nullptr) {
            traverse(root->right, level + 1);
        }
    }

    bool isCompleteTree(TreeNode* root) {

        v.clear();
        traverse(root, 0);

        int first_level = v[0];
        for (int i = 1; i < v.size(); ++i) {
            if (first_level != v[i]) {
                return false;
            }
        }

        return true;
    }
};


// level order traverse
class Solution {
public:

    bool isCompleteTree(TreeNode* root) {

        vector<TreeNode *> q;
        int level = 1;

        q.push_back(root);

        bool null_exist = false;
        while (!q.empty()) {
            vector<TreeNode *> tq;

            for (int i = 0; i < q.size(); ++i) {
                if (q[i]->left != nullptr) {
                    tq.push_back(q[i]->left);
                    if (null_exist == true) return false;
                }
                else {
                    null_exist = true;
                }

                if (q[i]->right != nullptr) {
                    tq.push_back(q[i]->right);
                    if (null_exist == true) return false;
                }
                else {
                    null_exist = true;
                }
            }

            q = tq;
        }

        return true;

    }
};



int main() {
    char c;
    Solution sol;

    vector<int> arr = { 1, 3, 5 };

    cout << sol.numOfSubarrays(arr);

    cin >> c;
}
