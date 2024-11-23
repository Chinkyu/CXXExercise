//  답봤음 : 위에서 물을 똑똑 떨어트리는 방식...  
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


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        else if (root->val > val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root = new TreeNode(pre[0]);
        for (int i = 1; i < pre.size(); i++) {
            root = insertIntoBST(root, pre[i]);
        }
        return root;
    }
}

class _Solution {
public:
    // Helper function to search for an element in the given vector
    int search(vector<int>&in, int t) {
        for (int i = 0; i < in.size(); i++) {
            if (in[i] == t)
                return i;
        }
        return -1;
    }

    // Recursive function to build a binary tree from preorder and inorder traversals
    TreeNode* build(vector<int>&pre, vector<int>&in, int& start, int ins, int ine) {
        // Base case: When the start index exceeds the end index, there are no more nodes to process
        if (ins > ine)
            return NULL;

        // Create a new node with the value at the current start index
        TreeNode* root = new TreeNode(pre[start]);

        // Find the index of the current node in the inorder traversal
        int ind = search(in, pre[start]);

        // Increment the start index to process the next node in the preorder traversal
        start++;

        // Recursively build the left and right subtrees
        root->left = build(pre, in, start, ins, ind - 1);
        root->right = build(pre, in, start, ind + 1, ine);

        // Return the root node of the binary tree
        return root;
    }

    // Function to construct a binary search tree from a preorder traversal
    TreeNode* bstFromPreorder(vector<int>&pre) {
        // Create a copy of the preorder traversal
        vector<int> in = pre;

        // Sort the copy to obtain the inorder traversal
        sort(in.begin(), in.end());

        // Start index for the preorder traversal
        int start = 0;

        // Build the binary tree recursively using the preorder and inorder traversals
        return build(pre, in, start, 0, in.size() - 1);
    }

};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 2, 10, 3, 2 };

    cout << sol.minimumRemoval(nums);

    cin >> c;
}