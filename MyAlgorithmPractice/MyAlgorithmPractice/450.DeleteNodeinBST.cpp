#include <iostream>
#include <vector>

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
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class _Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root) return nullptr;
		if (root->val == key) {
			if (!root->right) {
				TreeNode* left = root->left;
				delete root;
				return left;
			}
			else {
				TreeNode* right = root->right;
				while (right->left)
					right = right->left;
				swap(root->val, right->val);
			}
		}
		root->left = deleteNode(root->left, key);
		root->right = deleteNode(root->right, key);
		return root;
	}
};


class Solution {
public:
	bool isDone = false;
	TreeNode *removeRoot(TreeNode *r) {
		TreeNode *p, *q;
		p = q = r;

		// find left most right item
		if (r->left != NULL) {
			p = r->left;
			while (p->right != NULL) {
				q = p;
				p = p->right;
			}
		}

		// if this is end node
		if (p->left == NULL) {
			q->right = NULL;
			r->val = p->val;
			delete p;
			return r;
		}

		// find right most left item
		if (r->right != NULL) {
			p = r->right;
			while (p->left != NULL) {
				q = p;
				p = p->left;
			}
		}

		// if this is end node
		if (p->right == NULL) {
			q->left = NULL;
			r->val = p->val;
			delete p;
			return r;
		}

		return r;
	}

	TreeNode *traverse(TreeNode *r, int key) {
		if (isDone == true) return r;

		if (r->val < key) {
			if(r->right != NULL) traverse(r->right, key);
			else {
				isDone = true;
				return NULL;
			}
		}
		else if (r->val > key) {
			if (r->left != NULL) traverse(r->left, key);
			else {
				isDone = true;
				return NULL;
			}
		}
		else if (r->val == key) {
			r = removeRoot(r);
			isDone = true;
			return r;
		}
		return r;
	}

	TreeNode* deleteNode(TreeNode* root, int key) {

		isDone = false;

		root = traverse(root, key);
		return root;
	}
};

int main() {
	char c;
	Solution sol;

	TreeNode * root = new TreeNode(5);
	TreeNode *p = new TreeNode(3);
	p->left = new TreeNode(2);
	p->right = new TreeNode(4);
	root->left = p;

	p = new TreeNode(6);
	p->right = new TreeNode(7);

	root = sol.deleteNode(root, 3);

	cin >> c;
}