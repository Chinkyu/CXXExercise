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
	TreeNode* help(vector<int> &preorder, vector<int> &inorder, int frompre, int fromin, int size) {
		if (size == 0)
			return NULL;
		TreeNode* root = new TreeNode(preorder[frompre]);
		int i = fromin;
		while (inorder[i] != root->val)
			i++;
		root->left = help(preorder, inorder, frompre + 1, fromin, i - fromin);
		root->right = help(preorder, inorder, frompre + i + 1 - fromin, i + 1, size - i - 1 + fromin);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return help(preorder, inorder, 0, 0, (unsigned int)preorder.size());
	}
};

class _Solution {
	public:
		bool isFound = false;
		TreeNode *foundNode = NULL;
		void find_node(TreeNode *p, int value) {
			if (isFound == true) return;

			if (p->left != NULL) find_node(p->left, value);
			if (isFound == true) return;
			
			if (value == p->val) {
				isFound == true;
				foundNode = p;
				return;
			}

			if (p->right != NULL) find_node(p->right, value);
			if (isFound == true) return;


		}

		void inOrder(TreeNode *p) {
			if (p == NULL) return;
			if (p->left != NULL) inOrder(p->left);
			cout << p->val << " ";
			if (p->right != NULL) inOrder(p->right);
		}

		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			if (preorder.size() == 0 || inorder.size() == 0) return NULL;

			TreeNode * root, *p;
			
			root = p = new TreeNode(preorder[0]);

			for (int i = 1; i < preorder.size(); ++i) {
				int father_value = 0;
				// find i-1 from inorder
				for (int j = 0; j < inorder.size(); ++j) {
					if (preorder[i] == inorder[j]) {
						// j+1 is father
						if (j >= 1 && preorder[i - 1] == inorder[j - 1]) {
							// find father_value from root
							father_value = inorder[j - 1];
							isFound = false;
							find_node(root, father_value);
							foundNode->right = new TreeNode(preorder[i]);
							break;
						}
						else {
							father_value = inorder[j + 1];
							// find father_value from root
							isFound = false;
							find_node(root, father_value);
							foundNode->left = new TreeNode(preorder[i]);
//							if (i + 1 < preorder.size()) {
//								foundNode->right = new TreeNode(preorder[i + 1]);
//								i++;
//							}
							break;
						}
					}
				}
			}
			return root;
		}
};

int main() {
	char c;
	Solution sol;
//	vector<int> preorder = { 3, 9, 20, 15, 7 };
//	vector<int> inorder = { 9, 3, 15, 20, 7 };
//	vector<int> preorder = { 1,2};
//	vector<int> inorder = {  1,2};

	vector<int> preorder = { 1,2, 3};
	vector<int> inorder = { 2, 3, 1};


	TreeNode *p = sol.buildTree(preorder, inorder);

	sol.inOrder(p);

	cin >> c;
}
