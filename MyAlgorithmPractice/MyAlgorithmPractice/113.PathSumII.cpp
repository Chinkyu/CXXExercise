#include <iostream>
#include <stack>
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
	vector <vector<int>> ans;

	void traverse(TreeNode *p, int depth, int sum) {

		if (p == NULL) return;
		if (v.size() <= depth) v.resize(depth+1);
		v[depth] = p->val;
		if (p->left == NULL && p->right == NULL) {
			int s = 0;
			vector<int> v1;
			for (int i = 0; i <= depth; ++i) s += v[i];
			if (s == sum) {
				for (int i = 0; i <= depth; ++i) v1.push_back(v[i]);
				ans.push_back(v1);
			}
		}
		if (p->left != NULL) traverse(p->left, depth + 1, sum);
		if (p->right != NULL) traverse(p->right, depth + 1, sum);
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		ans.clear();
		v.clear();

		traverse(root, 0, sum);
		return ans;
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

	sol.pathSum(root, 20);

	cin >> c;
}
