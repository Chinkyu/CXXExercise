//  처음에 타임아웃이라 카운트 벡터를 가지고 사용하는것으로  풀림.. 

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
	int ans;
	void traverse(TreeNode *p, vector<int> &count) {

		count[p->val]++;

		if (p->left == NULL && p->right == NULL) {
			if (isPalandrom(count)) ans++;
			count[p->val]--;
			return;
		}

		if (p->left != NULL) traverse(p->left, count);
		if (p->right != NULL) traverse(p->right, count);

		count[p->val]--;
	}

	bool isPalandrom(vector<int> &count) {
		//vector<int> count(10, 0);  // from 1 to 9

		//for (auto it : path) count[it]++;

		int oneCount = 0;
		for (auto it : count) {
			if (it % 2 == 1) oneCount++;
		}

		if (oneCount == 0 || oneCount == 1) return true;
		return false;
	}

	int pseudoPalindromicPaths(TreeNode* root) {
		vector<int> count(10, 0);

		ans = 0;
		traverse(root, count);

		return ans;
	}
};


// timeout 
class _Solution {
public:
	vector<vector<int>> set;
	void traverse(TreeNode *p, vector<int> path) {

		path.push_back(p->val);

		if (p->left == NULL && p->right == NULL) {
			set.push_back(path);
			return;
		}

		if (p->left != NULL) traverse(p->left, path);
		if (p->right != NULL) traverse(p->right, path);
	}

	bool isPalandrom(vector<int> &path) {
		vector<int> count(10, 0);  // from 1 to 9

		for (auto it : path) count[it]++;

		int oneCount = 0;
		for (auto it : count) {
			if (it % 2 == 1) oneCount++;
		}

		if (oneCount == 0 || oneCount == 1) return true;
		return false;
	}

	int pseudoPalindromicPaths(TreeNode* root) {
		vector<int> path;
		set.clear();
		traverse(root, path);

		int ans = 0;
		for (auto it : set) {
			if (isPalandrom(it)) ans++;
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

//	cout << sol.pseudoPalindromicPaths()

	cin >> c;
}