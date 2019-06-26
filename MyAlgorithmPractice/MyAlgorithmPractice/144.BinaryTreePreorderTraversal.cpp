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
	vector<int> v;
	void traverse(TreeNode* p) {
		if (p == NULL) return;
		v.push_back(p->val);
		if (p->left != NULL) traverse(p->left);
		if (p->right != NULL) traverse(p->right);
	}

	vector<int> preorderTraversal(TreeNode* root) {
		v.clear();
		traverse(root);
		return v;
	}
};

int main() {


}