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
	TreeNode* help(vector<int> &inorder, vector<int> &postorder, int fromin, int frompost, int size) {
		if (size == 0)
			return NULL;
		TreeNode* root = new TreeNode(postorder[frompost]);
		int i = fromin;
		while (inorder[i] != root->val)
			--i;
		root->right = help(inorder, postorder, fromin, frompost - 1, fromin - i);
		root->left = help(inorder, postorder, i - 1, frompost - fromin + i - 1, size - fromin + i - 1);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return help(inorder, postorder, postorder.size() - 1, postorder.size() - 1, (unsigned int)postorder.size());
	}
};

int main() {
	char c;
	Solution sol;
	//	vector<int> preorder = { 3, 9, 20, 15, 7 };
	//	vector<int> inorder = { 9, 3, 15, 20, 7 };
	//	vector<int> preorder = { 1,2};
	//	vector<int> inorder = {  1,2};

	vector<int> preorder = { 1,2, 3 };
	vector<int> inorder = { 2, 3, 1 };


	TreeNode *p = sol.buildTree(preorder, inorder);

	sol.inOrder(p);

	cin >> c;
}
