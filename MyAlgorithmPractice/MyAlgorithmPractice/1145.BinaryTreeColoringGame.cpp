// Accepted... 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>

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

// 이런 방식으로 안되도 실제로  Node를 Count 해야함... ==> Done.. !!! 
class Solution {
public:
	int xlsum = 0, xrsum = 0, tsum = 0;
	int getSubNodeNumber(TreeNode* tn, int n, int x) {
		int sum = 1;
		int lsum = 0, rsum = 0;

		if (tn->left != NULL) lsum = getSubNodeNumber(tn->left, n, x);
		if (tn->right != NULL) rsum = getSubNodeNumber(tn->right, n, x);

		if (tn->val == x) {
			xlsum = lsum;
			xrsum = rsum;
		}

		return sum + lsum + rsum;
	}

	bool btreeGameWinningMove(TreeNode* root, int n, int x) {
		int l = x * 2, r = x * 2 + 1;

		tsum = getSubNodeNumber(root, n, x);

		int osum = tsum - xlsum - xrsum - 1; // other

		// if 1 be large than other two sum.  return true;
		if (xlsum > xrsum + osum + 1) return true;
		if (xrsum > xlsum + osum + 1) return true;
		if (osum > xlsum + xrsum + 1) return true;

		return false;
	}
};

class Solution1 {
public:

	int getSubNodeNumber(int n, int x) {
		int sum = 1;
		int l = x * 2, r = x * 2 + 1;

		if (l <= n) sum += getSubNodeNumber(n, l);
		if (r <= n) sum += getSubNodeNumber(n, r);

		return sum;
	}

	bool btreeGameWinningMove(TreeNode* root, int n, int x) {
		int l = x * 2, r = x * 2 + 1;
		int lsum = 0, rsum = 0;

		if (l <= n) lsum = getSubNodeNumber(n, l);
		if (r <= n) rsum = getSubNodeNumber(n, r);

		int osum = n - lsum - rsum - 1; // other


		// if 1 be large than other two sum.  return true;
		if (lsum > rsum + osum + 1) return true;
		if (rsum > lsum + osum + 1) return true;
		if (osum > lsum + rsum + 1) return true;

		return false;
	}
};



int main() {
	char c;
	Solution sol;

	cout << sol.btreeGameWinningMove(NULL, 5, 1) << endl;

	//	cout << "test : " << ans << endl;

	cin >> c;
}