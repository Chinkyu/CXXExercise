#include <iostream>
#include <vector>
#include <map>

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

class Solution {
public:
	map<int, int> max;

	void traverse(TreeNode *p, int level) {

		if (max.find(level) == max.end()) {
			max[level] = p->val;
		}
		else {
			if (max[level] < p->val) {
				max[level] = p->val;
			}
		}

		if (p->left != NULL) traverse(p->left, level + 1);
		if (p->right != NULL) traverse(p->right, level + 1);

	}

	vector<int> largestValues(TreeNode* root) {
		max.clear();
		vector<int> ans;
		if (root == NULL) return ans;

		traverse(root, 0);

		for (auto it : max) {
			ans.push_back(it.second);
		}
		return ans;
	}
};

