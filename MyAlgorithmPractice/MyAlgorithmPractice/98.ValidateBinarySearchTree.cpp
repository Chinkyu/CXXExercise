// from Lee code
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	long max;
	bool traverse(TreeNode * p) {
		if (p == NULL) return true;

		if (p->left != NULL) {
			if (traverse(p->left) == false) return false;
		}
		if (max >= p->val) return false;
		max = p->val;
		if (p->right != NULL) {
			if (traverse(p->right) == false) return false;
		}

		return true;
	}

	bool isValidBST(TreeNode * root) {
		max = LONG_MIN;
		return traverse(root);
	}
};

int main() {
	Solution sol;
	char c;

	vector<TreeNode*> ret = sol.generateTrees(3);

	for (auto it : ret) {
		cout << it->val << " ";
	}


	cin >> c;
}