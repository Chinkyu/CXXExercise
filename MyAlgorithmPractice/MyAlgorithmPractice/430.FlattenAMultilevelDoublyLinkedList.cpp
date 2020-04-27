#include <iostream>
#include <vector>

using namespace std;


// Definition for a Node.
class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;
};

class Solution {
public:
	Node* flatten(Node* head) {
		Node *p, *q, *r, *h;
		p = q = r = h = head;

		while (p != NULL) {
			if (p->child != NULL) {
				flatten(p->child);
				q = p->next;
				p->next = p->child;
				p->child->prev = p;
				p->child = NULL;
				// move forward
				while(p->next != NULL) p = p->next;
				// link with q
				p->next = q;
				if(q != NULL) q->prev = p;
			}
			p = p->next;
		}

		return h;
	}
};