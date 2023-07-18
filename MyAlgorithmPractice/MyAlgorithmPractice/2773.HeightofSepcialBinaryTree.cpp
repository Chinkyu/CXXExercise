//	((root->left != nullptr) && (root == root->left->right))   »ý°¢ÇÏ±âÈûµë
// ´ä ºÃÀ½.. 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <cmath>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//  
class Solution {
public:

	int heightOfTree(TreeNode* root) {
		if ((root->left != nullptr) &&
			(root == root->left->right)) {
			return 0;
		}

		int left, right;
		if (root->left != nullptr) {
			left = heightOfTree(root->left) + 1;
		}
		else {
			return 0;
		}
		if (root->right != nullptr) {
			right = heightOfTree(root->right) + 1;
		}
		else {
			return 0;
		}

		return max(left, right);
	}
};


// Still infinitive loop : wrong understanding of problem 
class __Solution {
public:
	int heightOfTree(TreeNode* root) {
		stack<TreeNode *> st;

		st.push(root);
		int depth = 0;
		while (st.size() != 0) {
			int n = st.size();
			depth++;
			for (int i = 0; i < n; ++i) {
				TreeNode * t = st.top();
				st.pop();
				if (t->left != nullptr) st.push(t->left);
				if (t->right != nullptr) st.push(t->right);
			}

		}
		return depth;
	}
};

// stack overflow :  wrong understding for the problem 
class _Solution {
public:
	int getDepthTraverse(TreeNode *root, int &depth, int level) {

		depth = max(depth, level);

		if (root->left != nullptr) {
			getDepthTraverse(root, depth, level + 1);
		}
		if (root->right != nullptr) {
			getDepthTraverse(root, depth, level + 1);
		}

		return depth;
	}

	int heightOfTree(TreeNode* root) {
		int depth = 0;
		return getDepthTraverse(root, depth, 0);
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> chalk = { 5, 1, 5 };
	cout << sol.chalkReplacer(chalk, 22);

	cin >> c;
}
