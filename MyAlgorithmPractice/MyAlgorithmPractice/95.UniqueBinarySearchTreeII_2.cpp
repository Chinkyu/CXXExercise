// from Lee code
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<TreeNode*> generateTreesInRange(int low, int high) const {
		if (low == high) {
			return { new TreeNode(low) };
		}
		else if (high < low) {
			return { nullptr };
		}

		vector<TreeNode*> ret;

		for (int root_val = low; root_val <= high; ++root_val) {
			auto left_combos = generateTreesInRange(low, root_val - 1);
			auto right_combos = generateTreesInRange(root_val + 1, high);

			for (auto l : left_combos) {
				for (auto r : right_combos) {
					auto t = new TreeNode(root_val);
					t->left = l;
					t->right = r;
					ret.push_back(t);
				}
			}
		}

		return ret;
	}

	vector<TreeNode*> generateTrees(int n) const {
		if (n < 1) {
			return {};
		}
		return generateTreesInRange(1, n);
	}
};

int main() {
	Solution sol;
	char c;

	vector<TreeNode*> ret = sol.generateTrees(3);

	for (auto it : ret) {
		cout << it->val << " ";
	}


	cin >> c;
}