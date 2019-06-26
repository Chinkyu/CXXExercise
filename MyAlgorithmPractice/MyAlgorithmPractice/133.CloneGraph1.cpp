#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
public:

	map<int, Node*> m;
	map<int, bool> v;
	stack<Node*> st;

	Node* cloneGraph(Node *p) {
		vector<Node*> n;
		m.clear();
		v.clear();
		st.empty();

		Node *ans;
		if (p == NULL) return NULL;
		st.push(p);

		m[p->val] = new Node(p->val, n);
		ans = m[p->val];
		v[p->val] = false;

		while (!st.empty()) {
			p = st.top();
			st.pop();

			if (v[p->val] == true) continue;

			for (auto it : p->neighbors) {
				if (m.find(it->val) == m.end()) {
					m[it->val] = new Node(it->val, n);
					v[it->val] = false;
				}
				m[p->val]->neighbors.push_back(m[it->val]);
				if (v[it->val] != true) st.push(it);
			}
			v[p->val] = true;
		}
		return ans;
	}
};

int main() {
	Solution sol;
	vector<Node*> v;
	char c;

	Node *p1 = new Node(1, v);
	Node *p2 = new Node(2, v);
	Node *p3 = new Node(3, v);
	Node *p4 = new Node(4, v);

	p1->neighbors.push_back(p2);
	p1->neighbors.push_back(p3);
	p1->neighbors.push_back(p4);

	p2->neighbors.push_back(p1);
	p2->neighbors.push_back(p3);
	p2->neighbors.push_back(p4);

	p3->neighbors.push_back(p1);
	p3->neighbors.push_back(p2);
	p3->neighbors.push_back(p4);

	p4->neighbors.push_back(p1);
	p4->neighbors.push_back(p2);
	p4->neighbors.push_back(p3);

	Node* ans = sol.cloneGraph(p1);

	cin >> c;
}