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
	void traverse(TreeNode * r, int i, int v, int d) {
		if (i == d -1) {
			TreeNode *p, *q;
			if (r->left != NULL) {
				p = new TreeNode(v);
				q = r->left;
				r->left = p;
				p->left = q;
			}
			else {
				r->left = new TreeNode(v);
			}
			if (r->right != NULL) {
				p = new TreeNode(v);
				q = r->right;
				r->right = p;
				p->right = q;
			}
			else {
				r->right = new TreeNode(v);
			}
			return;
		}

		if (r->left != NULL) traverse(r->left, i + 1, v, d);
		if (r->right != NULL) traverse(r->right, i + 1, v, d);
	}

    TreeNode* addOneRow(TreeNode* root, int v, int d) {
		TreeNode *p, *q;
		if (d == 1) {
			p = new TreeNode(v);
			p->left = root;
			root = p;
			return root;
		}
		traverse(root, 1, v, d);
		return root;
    }
};

int main() {



}