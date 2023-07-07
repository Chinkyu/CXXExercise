//	map 으로 쉽게 해결 
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
#include <cmath>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* parent;
};
*/

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* parent;
};

class Solution {
public:
	Node* lowestCommonAncestor(Node* p, Node * q) {
		unordered_map<Node *, int> m;

		while (p != nullptr) {
			m[p] = 1;
			p = p->parent;
		}

		while (q != nullptr) {
			if (m.find(q) != m.end()) {
				return q;
			}
			q = q->parent;
		}

		return nullptr;
	}
};


int main() {
	char c;

	Solution sol;
	cout << sol.countHousePlacements(7);

	cin >> c;
}
