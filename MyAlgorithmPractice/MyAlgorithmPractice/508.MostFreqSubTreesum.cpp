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
	map<int, int> m;
	int max = 0;

	Solution() {
		m.clear();
	}

	int traverse(TreeNode *p) {
		int sl = 0,  sr = 0;

		if (p->left != NULL) sl = traverse(p->left);
		if (p->right != NULL) sr = traverse(p->right);
		int sum = sl + sr + p->val;

		if (m.find(sum) == m.end()) {
			m[sum] = 1;
		}
		else {
			m[sum]++;
		}

		if (max < m[sum]) max = m[sum];
		return sum;
	}

	vector<int> findFrequentTreeSum(TreeNode* root) {
		vector<int> ans;
		max = 0;
		m.clear();

		if (root == NULL) return ans;

		traverse(root);

		for (auto it : m) {
			if (it.second == max) ans.push_back(it.first);
		}
		return ans;
	}
};

int main() {


}