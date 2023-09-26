//  몇가지 예외 처리....  시간 걸림

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

	bool findStart(vector<int> &start_history, TreeNode *r, int start) {

		start_history.push_back(r->val);
		if (r->val == start) return true;

		if (r->left != nullptr) {
			if (findStart(start_history, r->left, start)) return true;
			start_history.pop_back();
		}

		if (r->right != nullptr) {
			if (findStart(start_history, r->right, start)) return true;
			start_history.pop_back();
		}
		return false;
	}

	
	int getdistance(vector<int> &start_history, vector<int> &history) {
		int sl = start_history.size();
		int hl = history.size();
		int ml = min(sl, hl);

		int same_num = 0;
		for (int i = 0; i < ml; ++i) {
			if (start_history[i] != history[i]) break;
			same_num++;
		}
		
		return sl + hl - same_num * 2;
	}


	int max_distance = 0;
	int traverse(TreeNode *r, vector<int> &start_history, vector<int> &history) {

		history.push_back(r->val);

		if (r->left == nullptr && r->right == nullptr) {
			return getdistance(start_history, history);
		}

		int distance = 0;
		
		if (r->left != nullptr) {
			distance = traverse(r->left, start_history, history);
			history.pop_back();
		}

		if (r->right != nullptr) {
			distance = max(distance, traverse(r->right, start_history, history));
			history.pop_back();
		}

		return distance;
	}

	int amountOfTime(TreeNode* root, int start) {

		vector<int> history, start_history;

		findStart(start_history, root, start);
		int ans = traverse(root, start_history, history);
		if (ans < start_history.size() - 1) ans = start_history.size() - 1;
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<string> garbage = { "G", "P", "GP", "GG" };
	vector<int> travel = { 2, 4, 3 };

	cout << sol.garbageCollection(garbage, travel);

	cin >> c;
}