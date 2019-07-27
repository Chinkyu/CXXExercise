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
	vector<int> rv;
	void traverse(TreeNode* p, int depth) {
		if (p == NULL) return;

		if(p->left != NULL) traverse(p->left, depth+1);

		if(rv.size() <= depth) {
			rv.resize(depth+1);
		}
		rv[depth] = p->val;

		if(p->right != NULL) traverse(p->right, depth+1);
	}

    vector<int> rightSideView(TreeNode* root) {
		rv.clear();
		traverse(root, 0);
		return rv;
    }
};


int main() {
	Solution sol;
	char c;

	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	TreeNode *p = root->left;
	p->right = new TreeNode(5);
	p = root->right;
	p->right = new TreeNode(4);

	vector<int> v = sol.rightSideView(root);

	for(auto it : v) {
		cout << it << " ";
	}

	cin >> c;
}

