#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};


class Solution {
public:

	vector<int> oneLevel(queue<Node*> &f) {
		vector<int> l;
		queue<Node *> t;

		while(f.size() != 0) {
			l.push_back(f.front()->val);
			for (auto it : f.front()->children) {
				t.push(it);
			}
			f.pop();
		};

		f = t;
		return l;
	}

	vector<vector<int>> levelOrder(Node* root) {
		queue<Node *> f;
		vector <vector<int>> ans;

		if (root == NULL) return ans;
		f.push(root);

		do {
			ans.push_back(oneLevel(f));

		} while (f.size() != 0);
		return ans;
	}
};

int main() {

	Node * p = new Node(5);
	Node *q = new Node(6);
	vector<Node *> v = { p, q };

	Node *r = new Node(3);
	r->children = v;

	Node *s = new Node(2);
	Node *t = new Node(4);
	vector < Node *> v2 = { r, s, t };

	Node *root = new Node(1);
	root->children = v2;

	Solution sol;
	char c;

	vector<vector<int>> ans = sol.levelOrder(root);
	for (auto it : ans) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}

	cin >> c;
}