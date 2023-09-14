//  easy... just dps swap..
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
	TreeNode* reverseOddLevels(TreeNode* root) {
		queue<TreeNode *> q;

		q.push(root);
		int level = 0;
		while (!q.empty()) {
			vector<TreeNode *> tv;
			while (!q.empty()) {
				TreeNode *p = q.front();
				q.pop();
				if (p->left != nullptr) tv.push_back(p->left);
				if (p->right != nullptr) tv.push_back(p->right);
			}
			level++;

			int l = tv.size();
			if (level % 2 == 1) {  // reverse value;
				for (int i = 0; i < l / 2; ++i) {
					swap(tv[i]->val, tv[l - i - 1]->val);
				}
			}

			for (int i = 0; i < l; ++i) {
				q.push(tv[i]);
			}
		}

		return root;
	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.closestFair(99999999);

	cin >> c;
}