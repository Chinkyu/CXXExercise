// easy 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
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
	int traverse(TreeNode * root, int &cnt) {

		if (root == nullptr) return 0;

		int v = root->val;
		long long l = 0, r = 0;
		if (root->left != nullptr) {
			l = traverse(root->left, cnt);
		}

		if (root->right != nullptr) {
			r = traverse(root->right, cnt);
		}

		if (v == l + r) cnt++;

		return v + l + r;
	}

	int equalToDescendants(TreeNode* root) {

		int cnt = 0;

		traverse(root, cnt);

		return cnt;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> nums1 = { 0, 1, 1 }; // { 1, 1, 0, 1 };
	vector<int> nums2 = { 1, 0, 1 };// { 0, 1, 1, 0 };

	cout << sol.widestPairOfIndices(nums1, nums2);

	cin >> c;
}