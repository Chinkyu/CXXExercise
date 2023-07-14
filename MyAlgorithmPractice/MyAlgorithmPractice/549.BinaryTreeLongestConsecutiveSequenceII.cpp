//	답봤음.... 이것을 생각 하기가 아주 까다로운것 같다
// 답보고 이해 하는데도 시간이 걸림.. 
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

class Solution {
public:
	int longestConsecutive(TreeNode* root) {
		int longest = 0;
		dfs(root, root, longest);
		return longest;
	}

	pair<int, int> dfs(TreeNode * node, TreeNode * parent, int & longest) {
		if (NULL == node) {
			return make_pair(0, 0);
		}
		auto left = dfs(node->left, node, longest);
		auto right = dfs(node->right, node, longest);
		longest = max(longest, left.first + right.second + 1);
		longest = max(longest, left.second + right.first + 1);
		int inc = 0, dec = 0;
		if (node->val == parent->val + 1) {
			inc = max(left.first, right.first) + 1;
		}
		if (node->val == parent->val - 1) {
			dec = max(left.second, right.second) + 1;
		}
		return make_pair(inc, dec);
	}
};

int main() {
	char c;

	Solution sol;

	string s = "165462";
	cout << sol.minimumPartition(s, 60);

	cin >> c;
}
