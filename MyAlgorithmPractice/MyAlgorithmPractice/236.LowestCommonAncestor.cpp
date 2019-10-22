#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template<typename T, typename Container = std::deque<T>>
class iterable_stack
	: public std::stack<T, Container>
{
	using std::stack<T, Container>::c;

public:


	// expose just the iterators of the underlying container
	auto begin() { return std::begin(c); }
	auto end() { return std::end(c); }

	auto begin() const { return std::begin(c); }
	auto end() const { return std::end(c); }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode *> p_path;
	vector<TreeNode *> q_path;
	iterable_stack<TreeNode *> path;

	TreeNode *fp, *fq;
	void traverse(TreeNode *root) {
		if (root == NULL) return;
		TreeNode * p = root;

		path.push(p);
		if (p->left != NULL) traverse(p->left);
		if (p == fp) {
			for (auto it : path) p_path.push_back(it);
		}
		if (p == fq) {
			for (auto it : path) q_path.push_back(it);
		}
		if (p->right != NULL) traverse(p->right);
		path.pop();

	}


	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		p_path.clear();
		q_path.clear();
		path.empty();

		fp = p;
		fq = q;
		path.push(root);
		traverse(root);

		int size = (p_path.size() > q_path.size()) ? q_path.size() : p_path.size();
		for (int i = 0; i < size; ++i) {
			if (p_path[i] != q_path[i]) return p_path[i - 1];
		}
		return p_path[size - 1];
	}
};

int main() {
	char c;
	Solution sol;

	TreeNode *root = new TreeNode(3);
	TreeNode *p = root;
	TreeNode *pp, *pq;

	p->left = new TreeNode(5);
	//pp = p->left;
	p->right = new TreeNode(1);
	//pq = p->right;
	p = p->left;
	p->left = new TreeNode(6);
	pp = p->left;
	p->right = new TreeNode(2);
	p = p -> right;
	p->left = new TreeNode(7);
	p->right = new TreeNode(4);
	pq = p->right;

	p = root->right;
	p->left = new TreeNode(0);
	p->right = new TreeNode(8);

	TreeNode *ans = sol.lowestCommonAncestor(root, pp, pq);
	cout << ans->val;

	cin >> c;

}