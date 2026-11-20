// ok. 
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
    int max_cnt = 0;
    int max_zigzag(vector<int>& h) {
        int l = h.size();

        int cnt = 0;
        if (h.size() > 1) cnt = 1;
        for (int i = 1; i < l; ++i) {
            if (h[i - 1] != h[i]) {
                cnt++;
                max_cnt = max(max_cnt, cnt);
            }
            else { // ==
                cnt = 1;
                max_cnt = max(max_cnt, cnt);
            }
        }
        return max_cnt;
    }

    void traverse(TreeNode* p, vector<int>& h) {

        // leaf node
        if (p->left == nullptr && p->right == nullptr) {
            max_zigzag(h);
            return;
        }

        if (p->left != nullptr) {
            h.push_back(0);
            traverse(p->left, h);
            h.pop_back();
        }

        if (p->right != nullptr) {
            h.push_back(1);
            traverse(p->right, h);
            h.pop_back();
        }
    }


    int longestZigZag(TreeNode* root) {
        max_cnt = 0;
        vector<int> h;
        traverse(root, h);

        return max_cnt; // (max_cnt >= 1) ? max_cnt + 1 : 0;
    }
};

int main() {
    char c;
   
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;

    cout << sol.longestZigZag(root);

    cin >> c;
}
