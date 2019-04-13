#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *p, *q;

		if (head == NULL)  return NULL;

		p = head;
		if (p->next == NULL) return head;

		head = p->next;
		p->next = head->next;
		head->next = p;
		q = p;

		if (p->next == NULL) return head;
		p = p->next;


		while (p->next != NULL) {
			q->next = p->next;
			p->next = p->next->next;
			q->next->next = p;
			q = p;

			if (p->next != NULL) {
				p = p->next;
			}
			else {
				return head;
			}
		}
		return head;
	}
};


void dump(ListNode *h) {

	cout << h->val << " ";
	while (h->next != NULL) {
		h = h->next;
		cout << h->val << " ";
	} 
	cout << endl;
}

int main() {
	char c;
	Solution sol;
	ListNode *h, *p, *q;

	h = new ListNode(0);
	p = h;
	for (int i = 1; i < 4; ++i) {
		p -> next = new ListNode(i);
		p = p->next;
	}

	dump(h);
	h = sol.swapPairs(h);
	dump(h);

	cin >> c;
}
