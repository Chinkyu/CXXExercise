#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverse(ListNode *st) {
		ListNode *p, *q, *r;

		p = st;
		q = st->next;
		st->next = NULL;
		if (q == NULL) return st;
		if (q != NULL) r = q->next;

		do {
			r = q->next;
			q->next = p;
			p = q;
			q = r;
			//r = q;
			//if (r != NULL) r = r->next;

		} while (r != NULL);

		return p;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *ans;

		if (l1 == NULL || l2 == NULL) return NULL;
		ListNode *r1 = reverse(l1);
		ListNode *r2 = reverse(l2);

		ListNode *p = r1;
		ListNode *q = r2;

		ans = new ListNode(p->val + q->val);

		ListNode *r = ans;
		p = p->next;
		q = q->next;
		while (p != NULL || q != NULL) {
			if (p != NULL && q != NULL) {
				r->next = new ListNode(p->val + q->val);
				r = r->next;
				p = p->next;
				q = q->next;
			}
			else if (p != NULL & q == NULL) {
				r->next = new ListNode(p->val);
				r = r->next;
				p = p->next;
			}
			else if (p == NULL & q != NULL) {
				r->next = new ListNode(q->val);
				r = r->next;
				q = q->next;
			}
		}
		
		int carry = 0;
		p = q = ans;
		while (p != NULL) {
			p->val += carry;
			carry = 0;
			if (p->val >= 10) {
				carry = p->val / 10;
				p->val = p->val % 10;
			}
			q = p;
			p = p->next;
		}
		if (carry != 0) q->next = new ListNode(carry);

		p = reverse(ans);
		return p;
	}
};

int _main() {
	char c;
	Solution sol;

	ListNode *l1  = new ListNode(7);
	ListNode *p = l1;

	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(3);


	ListNode *l2 = new ListNode(5);
	p = l2;

	p->next = new ListNode(6);
	p = p->next;
	p->next = new ListNode(4);


	ListNode *ans = sol.addTwoNumbers(l1, l2);
	p = ans;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cin >> c;
	return -1;
}

int main() {
	char c;
	Solution sol;

	ListNode *l1 = new ListNode(5);

	ListNode *l2 = new ListNode(5);
	
	ListNode *ans = sol.addTwoNumbers(l1, l2);
	ListNode *p = ans;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cin >> c;
}