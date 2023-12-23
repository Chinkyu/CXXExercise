// easy
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>

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
	TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
		unordered_map<int, TreeNode *> node;
		unordered_map<int, int> parent;

		for (auto &it : descriptions) {
			if(node.find(it[0]) == node.end()) {
				node[it[0]] = new TreeNode(it[0]); // parents
			}
			if (node.find(it[1]) == node.end()) {
				node[it[1]] = new TreeNode(it[1]);  // child
			}

			if (it[2] == 1) {  // isLeft;
				node[it[0]]->left = node[it[1]];
			}
			else {
				node[it[0]]->right = node[it[1]];
			}
			parent[it[1]] = it[0];
		}

		// find root
		int root = descriptions[0][0];  // start from any
		while (parent.find(root) != parent.end()) root = parent[root];

		return node[root];
	}
};

int main() {
	char c;

	Solution sol;


	vector<int> nums = { 4, 6, 7, 3, 2 };
	cout << sol.singleDivisorTriplet(nums);

	cin >> c;

}