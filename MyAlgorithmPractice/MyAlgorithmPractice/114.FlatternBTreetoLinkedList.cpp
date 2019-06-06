#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void flatten(TreeNode* root) {
		TreeNode *p = root;
		stack<TreeNode *> st;

		if (p == NULL) return;
		st.push(root);

		while (!st.empty()) {
			p = st.top();
			st.pop();
			if (p->right != NULL) st.push(p->right);
			if (p->left != NULL) st.push(p->left);
			if (st.empty()) break;
			p ->right = st.top();
			p->left = NULL;
		}
	}
};

int main() {
	Solution sol;
	char c;

	TreeNode *root = new TreeNode(5);
	TreeNode *p = root;

	p->left = new TreeNode(4);
	p->right = new TreeNode(8);

	p->left->left = new TreeNode(11);
	p->right->left = new TreeNode(13);
	p->right->right = new TreeNode(4);

	sol.flatten(root);

	cin >> c;
}
