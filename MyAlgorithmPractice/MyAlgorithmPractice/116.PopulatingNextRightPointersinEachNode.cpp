#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class Solution {
public:
	vector<Node*> v;

	void traverse(Node *p, int dep) {
		if (p == NULL) return;
		if (v.size() <= dep + 1) v.resize(dep + 1);

		if (v[dep] != NULL) v[dep]->next = p;
		v[dep] = p;
		if (p->left == NULL) return;

		//		p->left->next = p->right;
		//		v[dep] = p->right;

		if (p->left != NULL) traverse(p->left, dep + 1);
		if (p->right != NULL) traverse(p->right, dep + 1);
	}

	Node* connect(Node* root) {
		traverse(root, 0);
		return root;
	}
};

int main() {
	Solution sol;
	char c;

	Node *root = new Node(1, NULL, NULL, NULL);
	Node *p = root;

	p->left = new Node(2, NULL, NULL, NULL);
	p->right = new Node(3, NULL, NULL, NULL);

	p->left->left = new Node(4, NULL, NULL, NULL);
	p->left->right = new Node(5, NULL, NULL, NULL);
	p->right->left = new Node(6, NULL, NULL, NULL);
	p->right->right = new Node(7, NULL, NULL, NULL);

	sol.connect(root);

	cin >> c;
}
