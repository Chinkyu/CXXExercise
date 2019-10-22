#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int kth, ans;
	bool isCancel;
	void traverse(TreeNode * root) {
		if (root == NULL || isCancel == true) return;
		TreeNode *p = root;

		if (p->left != NULL) traverse(p->left);
		kth--;
		if (kth == 0) {
			ans = p->val;
			isCancel = true;
			return;
		}
		if (p->right != NULL) traverse(p->right);


	}

	int kthSmallest(TreeNode* root, int k) {
		kth = k;
		isCancel = false;

		traverse(root);

		return ans;
	}
};

int main() {



}