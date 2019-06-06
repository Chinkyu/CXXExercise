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
	TreeNode *dummyRoot; 

	bool turn_right(TreeNode *p) {
		if (p == NULL) return false;
		if (p->left != NULL && p->left->right == NULL) {
			p->left->right = p;
			p = p->left;
			p->right->left = NULL;
			return true;
		}
		return false;
	}

	bool turn_left(TreeNode *p) {
		if (p == NULL) return false;
		if (p->right != NULL && p->right->left == NULL) {
			p->right->left = p;
			p = p->right;
			p->left->right = NULL;
			return true;
		}
		return false;
	}



	void print_tree() {
		// wide first traverse
		queue<TreeNode *> q;
		TreeNode *p;

		q.push(dummyRoot->right);

		while (q.size()) {
			p = q.front();
			q.pop();

			cout << p->val << " ";

			if (p->left == NULL & p->right == NULL) continue;

			if (p->left == NULL) {
				cout << "null  ";
			}
			else {
				q.push(p->left);
			}

			if (p->right == NULL) {
				cout << "null  ";
			}
			else {
				q.push(p->right);
			}
		}
		cout << endl;

	}

	void traverse(TreeNode *p) {

		if (p->left == NULL && p->right == NULL) return;

		// as it is 

		if(p->left != NULL) traverse(p->left);
		if(p->right != NULL) traverse(p->right);

		// try turn left
		int lc = 0;
		while (turn_left(p)) {
			lc++;
			print_tree();
			if (p->left != NULL) traverse(p->left);
			if (p->right != NULL) traverse(p->right);
		}
		// roll back
		while (lc--) turn_right(p);

		// try turn right
		int rc = 0;
		while (turn_right(p)) {
			rc++;
			print_tree();
			if (p->left != NULL) traverse(p->left);
			if (p->right != NULL) traverse(p->right);
		}
		// roll back
		while (rc--) turn_left(p);
	
		print_tree();
	}


	vector<TreeNode*> generateTrees(int n) {
		dummyRoot = new TreeNode(-1);
		TreeNode *p = dummyRoot;
		vector<TreeNode *> res;

		// generate 1->2->.....->n tree
		for (int i = 1; i <= n; ++i) {
			p->right = new TreeNode(i);
			p = p->right;
		}
		
		traverse(dummyRoot->right);

		return res;
	}
};

int main() {
	Solution sol;
	char c;

	sol.generateTrees(3);


	cin >> c;
}