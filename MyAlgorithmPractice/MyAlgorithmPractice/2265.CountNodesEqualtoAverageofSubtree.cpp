//   easy  贸澜 巩力 肋给 毫辑 秦干
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


class _Solution {
public:
	vector<int> v;

	int traverse(TreeNode * root) {
		int sum = 0;
		if (root->left != nullptr) sum += traverse(root->left);
		if (root->right != nullptr) sum += traverse(root->right);
		sum += root->val;
		v.push_back(root->val);
		return sum;
	}

	int averageOfSubtree(TreeNode* root) {
		v.clear();
		int sum = traverse(root);
		int avg = sum / v.size();
		sort(v.begin(), v.end());

		// binary search ; same or large with avg
		int lidx = 0, ridx = v.size();
		int midx = 0;
		while (lidx < ridx) {
			midx = (lidx + ridx) / 2;
			if (v[midx] < avg) {
				lidx = midx;
			}
			else if (avg < v[midx]) {
				ridx = midx;
			} else {  // same

				while (midx > 0 && v[midx - 1] == v[midx]) midx--;
				return v.size() - midx;
			}
		}

		while (midx > 0 && v[midx - 1] == v[midx]) midx--;
		return v.size() - midx;
	}
};

class Solution {
public:
	int ans = 0;

	vector<int> traverse(TreeNode * root) {
		int sum = 0;
		int cnt = 0;
		if (root->left != nullptr) {
			vector<int> t = traverse(root->left);
			sum += t[0];
			cnt += t[1];
		}
		if (root->right != nullptr) {
			vector<int> t = traverse(root->right);
			sum += t[0];
			cnt += t[1];
		}

		sum += root->val;
		cnt++;
		if (root->val == (sum / cnt)) ans++;

		return vector<int>({ sum, cnt });
	}

	int averageOfSubtree(TreeNode* root) {
		ans = 0;

		vector<int> t = traverse(root);
		//if (root->val == (t[0] / t[1])) ans++;

		return ans;
	}
};


int main() {
	char c;

	Solution sol;

	string pressedKeys = "222222222222222222222222222222222222"; // "22233";
	cout << sol.countTexts(pressedKeys);

	cin >> c;

}