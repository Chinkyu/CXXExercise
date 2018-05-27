#include <iostream>

using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p, *q;
		ListNode *h, *i, *j;
	
		bool isPDone = false;
		bool isQDone = false;

		p = l1;
		q = l2;
		h = new ListNode(p->val + q->val);
		i = h;
		do {
			if (p->next != NULL) p = p->next;
			else isPDone = true;
			if (q->next != NULL) q = q->next;
			else isQDone = true;

			int sum = 0;
			if (isPDone == false && isQDone == false) {
				sum = p->val + q->val;
			}
			else if (isPDone == false && isQDone == true) {
				sum = p->val;
			}
			else if (isPDone == true && isQDone == false) {
				sum = q->val;
			}
			else {
				break;
			}

			j = new ListNode(sum);
			i->next = j;
			i = j;

		} while (!(isPDone == true && isQDone == true));

	// normalize 
		int carry = 0;
		p = h;
		do {
			p->val += carry;
			if (p->val >= 10) {
				carry = p->val / 10;
				p->val %= 10;
			}
			else carry = 0;
			if (p->next != NULL) {
				p = p->next;
			}
			else {
				break;
			}
		} while (true);
		
		// Handle last carry 
		if (carry > 0) {
			j = new ListNode(carry);
			p->next = j;
		}

		return h;
	}
};

ListNode * add_List(ListNode *p, int v) {

	if (p != NULL) {
		while (p->next != NULL) p = p->next;
		p->next = new ListNode(v);
	}
	else {
		p = new ListNode(v);
	}

	return p;
}

void print_List(ListNode *p) {
	ListNode *q;
	for (q = p; q->next != NULL; q = q->next) {
		cout << " " << q->val;
	}
	cout << " " << q->val;

	int i;
	for (i = 0; i != 3; i++);
	cout << i;
}

int main() {
	int i;

	Solution sol;

	ListNode *l = NULL;
	ListNode *r = NULL;
	ListNode *a = NULL;

	l = add_List(l, 2);
	add_List(l, 4);
	add_List(l, 3);

	r = add_List(r, 5);
	add_List(r, 6);
	add_List(r, 4);

	a = sol.addTwoNumbers(l, r);

	print_List(a);

	cin >> i;

}