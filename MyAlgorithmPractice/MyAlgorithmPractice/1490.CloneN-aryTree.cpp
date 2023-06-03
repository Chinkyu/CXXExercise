// 쉽게 풀림.


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

/*
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
*/

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

	Node* cloneTree(Node* root) {
		if (root == nullptr) return nullptr;

		Node * r = new Node(root->val);
		if (root->children.size() == 0) return r;

		for (auto it : root->children) {
			r->children.push_back(cloneTree(it));
		}

		return r;
	}
};

int main() {
	char c;
	Solution sol;

	string answerKey = "TFFT";
	cout << sol.maxConsecutiveAnswers(answerKey, 1);
	cin >> c;
}