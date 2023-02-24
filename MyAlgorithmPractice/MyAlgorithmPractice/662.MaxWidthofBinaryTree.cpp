// 이놈은 알고리즘으로 돌리면.. 큰수의 계산으로 해서 long long도 넘어가게 됨
// 한 라인을 계산한 후에 min 값을 모두 빼서 다음턴에 계산 하게 함. 
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
	 int widthOfBinaryTree(TreeNode* root) {
		 queue<pair<TreeNode *, long long>> q;
		 int max_gap = INT_MIN;

		 root->val = 1;
		 q.push(pair<TreeNode *, long long>(root, 1));

		 do {
			 long long min = INT_MAX, max = INT_MIN;
			 queue<pair<TreeNode *, long long>> tq;
			 while (!q.empty()) {
				 TreeNode *p = q.front().first;
				 long long seq = q.front().second;
				 q.pop();

				 if (seq < min) min = seq;
				 if (max < seq) max = seq;

				 if (p->left != NULL) {
					 long long nseq = seq * 2;
					 tq.push(pair<TreeNode*, long long>(p->left, nseq));

				 }

				 if (p->right != NULL) {
					 long long nseq = seq * 2 - 1;
					 tq.push(pair<TreeNode*, long long>(p->right, nseq));
				 }

			 }

			 if (max_gap < (max - min + 1)) max_gap = max - min + 1;

			 while (!tq.empty()) {
				 q.push(pair < TreeNode *, long long>(tq.front().first, tq.front().second - min));
				 tq.pop();
			 }

			 //q = tq;

		 } while (!q.empty());

		 return max_gap;
	 }
 };



class _Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		queue<pair<TreeNode *, int>> q;
		int max_gap = INT_MIN;

		root->val = 1;
		q.push(pair<TreeNode *, int>(root,1));

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
					tq.push(pair<TreeNode*, int>(p->left,nseq));

				}

				if (p->right != NULL) {
					int nseq = seq * 2 - 1;
					tq.push(pair<TreeNode*, int>(p->right,nseq));
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