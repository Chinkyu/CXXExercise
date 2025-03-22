// simple... 

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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> res;
    void traverse(TreeNode* root, vector<int> &entry)
    {
        if (nullptr == root)
            return;
        entry.push_back(root->val);
        traverse(root->left, entry);
        traverse(root->right, entry);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> v1;
        traverse(root1, v1);
        traverse(root2, v1);

        sort(v1.begin(), v1.end());
        return v1;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> costs = { 1,6,3,1,2,5 };

    cout << sol.maxIceCream(costs, 20);

    cin >> c;
}