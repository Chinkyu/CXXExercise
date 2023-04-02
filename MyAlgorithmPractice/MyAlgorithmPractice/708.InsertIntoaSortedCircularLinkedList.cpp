// 디버깅이 쉽지 않아 웹에서 했고.. 
// 몇번 트라이에서 해결 함.. 

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
	Node* next;

	Node() {}

	Node(int _val) {
		val = _val;
		next = NULL;
	}

	Node(int _val, Node* _next) {
		val = _val;
		next = _next;
	}
};
*/

class Node {
public:
	int val;
	Node* next;

	Node() {}

	Node(int _val) {
		val = _val;
		next = NULL;
	}

	Node(int _val, Node* _next) {
		val = _val;
		next = _next;
	}
};


class Solution {
public:
	Node* insert(Node* head, int insertVal) {
		Node*p, *q;

		if (head == NULL) {
			q = new Node(insertVal);
			q->next = q;
			return q;
		}

		p = q = head;
		if (p->next == p) {
			q = new Node(insertVal);
			p->next = q;
			q->next = p;
			return head;
		}

		p = p->next;
		bool isAllSame = true;
		int same_val = q->val;
		do {
			if (q->val != same_val) isAllSame = false;

			if (q->val > p->val) { // roll over point
				if (q->val <= insertVal || insertVal <= p->val) {
					Node *r = new Node(insertVal);
					q->next = r;
					r->next = p;
					return head;
				}
			}
			else if (q->val <= insertVal && insertVal <= p->val) {
				Node *r = new Node(insertVal);
				q->next = r;
				r->next = p;
				return head;
			}

			q = p;
			p = p->next;

		} while (q != head);

		if (isAllSame == true) {
			Node *r = new Node(insertVal);
			p = head->next;
			head->next = r;
			r->next = p;
			return head;
		}

		return NULL;
	}
};

int main() {
	char c;

	Solution sol;

	//vector<int> fronts = { 1, 2, 4, 4, 7 };
	//vector<int> backs = {1, 3, 4, 1, 3};

	//vector<int> arr = { 2, 4,5 , 10 };
	vector<int> arr = { 18, 3, 6, 2 };
	//vector<int> arr = { 4, 2 };

	cout << sol.numFactoredBinaryTrees(arr);


	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}