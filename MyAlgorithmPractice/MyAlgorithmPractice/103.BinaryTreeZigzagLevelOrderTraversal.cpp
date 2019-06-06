#include <iostream>
#include <vector>
#include <deque>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		deque<TreeNode *> q;
		vector<vector<int>> res;

		if (root == NULL) return res;

		q.push_back(root);

		for (int i = 0; q.size() > 0;  ++i) {
			vector<int> t;
			for (int j = q.size(); j > 0; --j) {
				if (i % 2 == 0) {
					TreeNode *t1 = q.front();
					q.pop_front();//  pop();
					t.push_back(t1->val);
					if (t1->left != NULL) q.push_back(t1->left);
					if (t1->right != NULL) q.push_back(t1->right);
				}
				else {
					TreeNode *t1 = q.back();
					q.pop_back();
					t.push_back(t1->val);
					if (t1->right != NULL) q.push_front(t1->right);
					if (t1->left != NULL) q.push_front(t1->left);
				}
			}
			res.push_back(t);
		}


		return res;
	}
};

int main() {


}