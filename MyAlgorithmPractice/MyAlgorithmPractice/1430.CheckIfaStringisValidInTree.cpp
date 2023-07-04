//	쉽게 풀림
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
	vector<int> path;
	bool isFound = false;
	void traverse(TreeNode *r, vector<int>& arr) {
		if (isFound == true) return;

		if (r->left == nullptr && r->right == nullptr) {
			// check arr
			path.push_back(r->val);
			if (path == arr) isFound = true;
			path.pop_back();
			return;
		}

		if (r->left != nullptr) {
			path.push_back(r->val);
			traverse(r->left, arr);
			path.pop_back();
		}

		if (r->right != nullptr) {
			path.push_back(r->val);
			traverse(r->right, arr);
			path.pop_back();
		}
		
	}

	bool isValidSequence(TreeNode* root, vector<int>& arr) {
		path.clear();
		isFound = false;
		traverse(root, arr);
		return isFound;
	}
};

int main() {
	char c;

	Solution sol;
	vector<string> nums = { "abc","deq","mee","aqq","dkd","ccc" };
	vector<string> ans = sol.findAndReplacePattern(nums, "abb");

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}