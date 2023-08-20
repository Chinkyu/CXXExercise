// copy answer - Need to check later 
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


// 몇변 돌리면 되는지를 찾는것이 관건임... 
class Solution {
public:

	//  이함수가 예술이구만... 
	int getRotationCount(vector<int> &v) {
		vector<pair<int, int>> vp;

		int n = v.size();
		for (int i = 0; i < n; ++i) {
			vp.push_back({ v[i], i });
		}
		sort(vp.begin(), vp.end());

		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (i != vp[i].second) {
				cnt++;
				swap(vp[vp[i].second], vp[i]);
				i--;
			}
		}
		return cnt;
	 }



	int minimumOperations(TreeNode* root) {
		// get each level's array and count not maching one -1
		queue<TreeNode *> q;
		int ans = 0;

		q.push(root);
		while (!q.empty()) {
			queue<TreeNode *> nq;
			vector<int> v;
			do {
				TreeNode *t = q.front();
				if (t->left != nullptr) {
					nq.push(t->left); 
					v.push_back(t->left->val);
				}
				if (t->right != nullptr) {
					nq.push(t->right);
					v.push_back(t->right->val);
				}
				q.pop();
			} while (!q.empty());

			q = nq;

#if 0
			// check how many mismatch
			vector<int> sv = v;
			sort(sv.begin(), sv.end());
			int notMatch = 0;
			unordered_map<set<int>, int> ms;
			for (int i = 0; i < v.size(); ++i) {
				if (v[i] != sv[i]) {
					notMatch++;
					set<int> s; 
					s.insert(v[i]); s.insert(sv[i]);
					ms[s] = 1;
				}
			}
			int setNum = ms.size();
#endif

			ans += getRotationCount(v);
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	vector<vector<int>> roads = { {0, 1},{0, 2},{0, 3} };

	cout << sol.minimumFuelCost(roads, 5);

	cin >> c;
}