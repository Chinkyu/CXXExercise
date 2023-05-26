// 쉽게 풀림... 

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
	int ans = 1;
	int getConseqLen(vector<int> &v) {
		int maxConsqLen = 0;

		int consqLen = 1;
		int prevV = v[0];

		for (int i = 1; i < v.size(); ++i) {
			if (v[i] == prevV + 1) {
				consqLen++;
				prevV = v[i];
				if (maxConsqLen < consqLen) maxConsqLen = consqLen;
			}
			else {
				consqLen = 1;
				prevV = v[i];
			}
		}
		return maxConsqLen;
	}

	void traverse(TreeNode *p, vector<int> &v) {

		v.push_back(p->val);
		if (p->left == nullptr && p->right == nullptr) {
			int len = getConseqLen(v);
			if (ans < len) ans = len;
			v.pop_back();
			return;
		}

		if (p->left != nullptr) traverse(p->left, v);
		if (p->right != nullptr) traverse(p->right, v);
		v.pop_back();
	}

	int longestConsecutive(TreeNode* root) {
		ans = 1;
		vector<int> v;
		traverse(root, v);

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	string s = "01101110"; //  "011010";
	cout << sol.canReach(s, 2, 3);

	cin >> c;
}