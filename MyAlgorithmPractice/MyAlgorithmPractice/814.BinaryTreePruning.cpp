//  root°¡ nullprt ÀÎ°æ¿ì »©°í´Â ½¬¿üÀ½

#include <iostream>
#include <vector>
#include <unordered_map>
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

	int traverse(TreeNode *r) {
		int lval = 0, rval = 0;
		if (r->left != nullptr) {
			lval = traverse(r->left);
			if (lval == 0) r->left = nullptr;
		}

		if (r->right != nullptr) {
			rval = traverse(r->right);
			if (rval == 0) r->right = nullptr;
		}

		return (lval | rval | r->val);
	}

	TreeNode* pruneTree(TreeNode* root) {
		int val = traverse(root);
		if (root->val == 0 && val == 0) return nullptr;
		return root;
	}
};

int main() {
	char c;

	Solution sol;

	//vector<int> nums = { 9, 1, 2, 3, 9 };
	//cout << sol.largestSumOfAverages(nums, 3);


	//vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
	//cout << sol.largestSumOfAverages(nums, 4);


	vector<int> nums = { 4663, 3020, 7789, 1627, 9668, 1356, 4207, 1133, 8765, 4649, 205, 6455, 8864, 3554, 3916, 5925, 3995, 4540, 3487, 5444, 8259, 8802, 6777, 7306, 989, 4958, 2921, 8155, 4922, 2469, 6923, 776, 9777, 1796, 708, 786, 3158, 7369, 8715, 2136, 2510, 3739, 6411, 7996, 6211, 8282, 4805, 236, 1489, 7698 };
	cout << sol.largestSumOfAverages(nums, 27);

	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}