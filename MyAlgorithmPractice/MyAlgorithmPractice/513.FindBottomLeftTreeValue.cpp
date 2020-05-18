#include <iostream>
#include <vector>

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
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int max_level = 0;
	int v = 0;
	bool isFound = false;

	void traverse(TreeNode *p, int level) {

		if (max_level < level) {
			v = p->val;
			max_level = level;
		}

		if (p->left != NULL) traverse(p->left, level + 1);
		if (p->right != NULL) traverse(p->right, level + 1);

	}

	int findBottomLeftValue(TreeNode* root) {
		max_level = 0;
		v = root->val;
		isFound = false;

		traverse(root, 0);
		return v;
	}
};

