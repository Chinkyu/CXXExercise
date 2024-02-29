// tricky in debugging :
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

// timout
class Solution {
public:

	bool find(TreeNode *r, vector<int> &path, int v) {

		if (r->val == v) {
			return true;
		}


		if (r->left != nullptr) {
			path.push_back(-1);
			if (true == find(r->left, path, v)) return true;
		}

		if (r->right != nullptr) {
			path.push_back(1);
			if (true == find(r->right, path, v)) return true;
		}

		path.pop_back();
		return false;
	}

	string getDirections(TreeNode* root, int startValue, int destValue) {
		vector<int> sPath, ePath;


		// track start 
		find(root, sPath, startValue);


		// track dest
		find(root, ePath, destValue);

		// remove same node 
		int idx = 0;
		for (int i = 0; i < min(sPath.size(), ePath.size()); +i) {
			if (sPath[i] != ePath[i]) {
				idx = i;
				break;
			}
			idx = i + 1;
		}

		//while (sPath[idx] == ePath[idx]) idx++;

		// make result
		string ans;
		for (int i = 0; i < sPath.size() - idx; ++i) ans.push_back('U');
		for (int i = idx; i < ePath.size(); ++i) ans.push_back((ePath[i] == 1) ? 'R' : 'L');

		return ans;
	}
};

class _Solution {
public:

	bool find(TreeNode *r, vector<int> &path, int v) {

		if (r->val == v) {
			return true;
		}


		if (r->left != nullptr) {
			path.push_back(-1);
			if (true == find(r->left, path, v)) return true;
		}

		if (r->right != nullptr) {
			path.push_back(1);
			if (true == find(r->right, path, v)) return true;
		}

		path.pop_back();
		return false;
	}

	string getDirections(TreeNode* root, int startValue, int destValue) {
		vector<int> sPath, ePath;


		// track start 
		find(root, sPath, startValue);


		// track dest
		find(root, ePath, destValue);

		// remove same node 
		int idx = 0;
		for (int i = 0; i < min(sPath.size(), ePath.size()); ++i) {
			if (sPath[i] != ePath[i]) {
				idx = i;
				break;
			}
		}

		//while (sPath[idx] == ePath[idx]) idx++;

		// make result
		string ans;
		for (int i = 0; i < sPath.size() - idx; ++i) ans.push_back('U');
		for (int i = idx; i < ePath.size(); ++i) ans.push_back((ePath[i] == 1) ? 'R' : 'L');

		return ans;
	}
};



int main() {
	char c;

	Solution sol;

	vector<int> nums = { 20,17,0,2,7 }; // { 1, 5, 5, 5, 4 };

	cout << sol.largestEvenSum(nums, 2);

	cin >> c;
}