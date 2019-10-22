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
	vector<int> lValue;
	int cnt;
	void traverse(TreeNode *root, int level) {
		TreeNode *p = root;
		if (p == NULL) return;

		if (lValue.size() < level + 1) lValue.resize(level + 1);
		lValue[level] = p->val;
		cnt++;
		if (p->left != NULL) traverse(p->left, level + 1);
		if (p->right != NULL) traverse(p->right, level + 1);
	}

    int countNodes(TreeNode* root) {
		TreeNode * p = root;

		if (p == NULL) return 0;

		cnt = 0;
		traverse(root, 0);

		// fine last value in lValue;
//		int ans = 0;

//		for (auto it : lValue) ans = it;
		return cnt;
    }
};

int main() {
	Solution sol;
	char c;

	Sol.countNodes();

}
