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
	vector<int> traject;
	int sum;

	void traverse(TreeNode *p, int idx) {

		if (p == NULL) return;
		if (traject.size() < idx+1) traject.resize(idx+1);
		traject[idx] = p->val;

		if (p->left == NULL && p->right == NULL) {
			int t = 0;
			for (int i = 0; i <= idx; ++i) {
				t += traject[i] * pow(10, idx - i);
			}
			sum += t;
			return;
		}

		if (p->left != NULL) traverse(p->left, idx + 1);
		if (p->right != NULL) traverse(p->right, idx + 1);
	}

	int sumNumbers(TreeNode* root) {
		traject.clear();
		sum = 0;

		traverse(root, 0);
		return sum;
	}
};

int main() {
	Solution sol;
	char c;

	TreeNode *root = new TreeNode(1);
	TreeNode *p = root;

	p->left = new TreeNode(2);
	p->right = new TreeNode(3);

//	p->left->left = new TreeNode(4, NULL, NULL, NULL);
//	p->left->right = new TreeNode(5, NULL, NULL, NULL);
//	p->right->left = new TreeNode(6, NULL, NULL, NULL);
//	p->right->right = new TreeNode(7, NULL, NULL, NULL);

	cout << sol.sumNumbers(root);

	cin >> c;
}
