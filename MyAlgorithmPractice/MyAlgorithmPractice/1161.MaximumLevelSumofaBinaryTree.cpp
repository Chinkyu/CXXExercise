// 쉽게 풀림
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

/** * Definition for a binary tree node. * struct TreeNode { *     int val; *     TreeNode *left; *     TreeNode *right; *     TreeNode() : val(0), left(nullptr), right(nullptr) {} *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} * }; */
struct TreeNode {	int val;	TreeNode *left;	TreeNode *right;	TreeNode() : val(0), left(nullptr), right(nullptr) {}	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}};

class Solution {
public:	map<int, int> m;	void traverse(TreeNode * root, int level) {		m[level] += root->val;		if (root->left != nullptr) {			traverse(root->left, level + 1);		}		if (root->right != nullptr) {			traverse(root->right, level + 1);		}	}
	int maxLevelSum(TreeNode* root) {		m.clear();
		traverse(root, 1);
		// find min		int min_val = INT_MIN;		int min_level = 0;		for (auto it : m) {			if (it.second > min_val) {				min_level = it.first;				min_val = it.second;			}		}		return min_level;
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> data = { 1,0,1,0,1,0,0,1,1,0,1 };
	cout << sol.minSwaps(data);

	//vector<vector<int>> clips = {{0, 5}, {1, 6}, {2, 7}, {3, 8}, {4, 9}, {5, 10}, {6, 11}, {7, 12}, {8, 13}, {9, 14}, {10, 15}, {11, 16}, {12, 17}, {13, 18}, {14, 19}, {15, 20}, {16, 21}, {17, 22}, {18, 23}, {19, 24}, {20, 25}, {21, 26}, {22, 27}, {23, 28}, {24, 29}, {25, 30}, {26, 31}, {27, 32}, {28, 33}, {29, 34}, {30, 35}, {31, 36}, {32, 37}, {33, 38}, {34, 39}, {35, 40}, {36, 41}, {37, 42}, {38, 43}, {39, 44}, {40, 45}, {41, 46}, {42, 47}, {43, 48}, {44, 49}, {45, 50}, {46, 51}, {47, 52}, {48, 53}, {49, 54}};
	//cout << sol.videoStitching(clips, 50);


	cin >> c;
}