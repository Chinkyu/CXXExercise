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

	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode *> q;
		vector<vector<int>> res;

		if (root == NULL) return res;

		q.push(root);

		while (q.size() != 0) {
			vector<int> t;
			for (int i = q.size(); i > 0; --i) {
				TreeNode *t1 = q.front();
				q.pop();
				t.push_back(t1->val);
				if (t1->left != NULL) q.push(t1->left);
				if (t1->right != NULL) q.push(t1->right);
			}
			res.push_back(t);
		}


		return res;
	}
};

int main() {


}