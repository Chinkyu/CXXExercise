#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
	void traverse(TreeNode *r, string &s) {

		s.append(to_string(r->val) + " ");
		if (r->left != NULL) {
			s.append("l ");
			traverse(r->left, s);
		}
		if (r->right != NULL) {
			s.append("r ");
			traverse(r->right, s);
		}
		s.append("u ");
	}
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string s;

		if (root == NULL) return s;

		traverse(root, s);
		return s;
	}

	void buildTree(TreeNode *r, istringstream &input) {
		string n;
		int val;

		while(true) {
			getline(input, n, ' ');

			if (n[0] == 'l') {
				getline(input, n, ' ');
				val = stoi(n);
				r->left = new TreeNode(val);
				buildTree(r->left, input);
			}
			if (n[0] == 'r') {
				getline(input, n, ' ');
				val = stoi(n);
				r->right = new TreeNode(val);
				buildTree(r->right, input);
			}
			if (n[0] == 'u') return;
		};
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream input(data);
		TreeNode *root;

		if (data.size() <= 0) return NULL;
		string n;
		int val;

		getline(input, n, ' ');
		val = stoi(n);
		root = new TreeNode(val);

		buildTree(root, input);
		return root;
	}
};


int main() {
	char c;

	Codec codec;

	TreeNode * root = new TreeNode(4);

	TreeNode *p = new TreeNode(3);
	p->left = new TreeNode(1);
	p->right = new TreeNode(2);
	root->left = p;

	p = new TreeNode(5);
	p->left = new TreeNode(6);
	p->right = new TreeNode(7);
	root->right = p;

	string s = codec.serialize(root);
	cout << s.c_str() << endl;

	p = codec.deserialize(s);

	s = codec.serialize(p);
	cout << s.c_str() << endl;

	cin >> c;
}