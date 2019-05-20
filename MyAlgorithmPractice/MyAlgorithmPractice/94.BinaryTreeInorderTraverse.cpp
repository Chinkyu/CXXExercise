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
	vector<int> journey;

	void inorder(TreeNode *p) {
		if (p == NULL) return;

		if (p->left != NULL) inorder(p->left);
		journey.push_back(p->val);
		if (p->right != NULL) inorder(p->right);
	}

	vector<int> inorderTraversal(TreeNode* root) {
		journey.clear();

		inorder(root);
		return journey;
	}
};

int main() {
	char c;
	Solution sol;


	sol.inorderTraversal

}
