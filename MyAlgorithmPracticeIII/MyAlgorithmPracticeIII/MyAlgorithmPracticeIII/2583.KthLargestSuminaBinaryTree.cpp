// easy : 
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> lev;

        TreeNode* p = root;
        vector <TreeNode*> nxt;
        nxt.push_back(root);
        while (!nxt.empty()) {
            long long csum = 0;
            vector<TreeNode*> tnxt;
            for (auto& it : nxt) {
                csum += it->val;
                if (it->left != nullptr) tnxt.push_back(it->left);
                if (it->right != nullptr) tnxt.push_back(it->right);
            }

            lev.push_back(csum);
            nxt = tnxt;
        }

        if (lev.size() < k) return -1;

        sort(lev.begin(), lev.end(), greater<long long>());

        return lev[k - 1];
    }
};


int main() {
    char c;
    Solution sol;
    //vector<int> asteroids = {5, 10, -5};
    vector<int> asteroids = { -2,1,-1,-2 };

    vector<int> ans = sol.asteroidCollision(asteroids);

    for (auto& it : ans) {
        cout << it << " ";
    }

    //cout << "Test  application";

    cin >> c;
}
