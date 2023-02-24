// 큰 어려움 없이... 해결 .. 
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
	unordered_map<int, bool> m;

	int traverse(TreeNode * r) {
		int below_sum = 0;

		if (r->left == NULL && r->right == NULL) {
			m[r->val] = true;
			return r->val;
		}

		if (r->left != NULL) below_sum += traverse(r->left);
		if (r->right != NULL) below_sum += traverse(r->right);

		r->val += below_sum;

		m[r->val] = true;
		return r->val;
	}

	bool checkEqualTree(TreeNode* root) {
		m.clear();

		int total_sum = traverse(root);
			   
		if ((total_sum & 0x01) == 0x01) return false;  // odd number false;

		// if total is 0,  if one of sub is 0 -> true.. if not false
		if (total_sum == 0) {
			if (root->left != NULL && root->left->val == 0) return true;
			if (root->right != NULL && root->right->val == 0) return true;
			return false;
		}
		if (m.find(total_sum / 2) != m.end()) return true;

		return false;
	}
};



class _Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		queue<pair<TreeNode *, int>> q;
		int max_gap = INT_MIN;

		root->val = 1;
		q.push(pair<TreeNode *, int>(root, 1));

		do {
			int min = INT_MAX, max = INT_MIN;
			queue<pair<TreeNode *, int>> tq;
			while (!q.empty()) {
				TreeNode *p = q.front().first;
				int seq = q.front().second;
				q.pop();

				if (seq < min) min = seq;
				if (max < seq) max = seq;

				if (p->left != NULL) {
					int nseq = seq * 2;
					tq.push(pair<TreeNode*, int>(p->left, nseq));

				}

				if (p->right != NULL) {
					int nseq = seq * 2 - 1;
					tq.push(pair<TreeNode*, int>(p->right, nseq));
				}

			}

			if (max_gap < (max - min + 1)) max_gap = max - min + 1;
			q = tq;
		} while (!q.empty());

		return max_gap;
	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.numSteps("1101");
	//	cout << "test : " << ans << endl;

	cin >> c;
}