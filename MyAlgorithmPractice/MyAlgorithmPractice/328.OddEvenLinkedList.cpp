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
	ListNode* oddEvenList(ListNode* head) {
		ListNode *e, *o = head, *p = head;
		
		if (p == NULL) return NULL;
		if (p->next == NULL) return head;
		ListNode *oHead = o = p;
		ListNode *eHead = e = p->next;
		p = p->next->next;
		for (int i = 1; p != NULL; p = p->next, ++i) {
			if (i % 2 == 1) {
				o->next = p;
				o = o->next;
			}
			else {
				e->next = p;
				e = e->next;
			}
		}
		o->next = NULL;
		e->next = NULL;


		head = oHead;
		o->next = eHead;
		return head;
	}
};


int main() {
	char c;
	Solution sol;

	vector<int> v = { 1, 2, 3, 4, 5 };

	ListNode *head, *p;
	head = p = new ListNode(v[0]);
	for (int i = 1; i < v.size(); i++) {
		p -> next = new ListNode(v[i]);
		p = p->next;
	}

	ListNode *ans = sol.oddEvenList(head);

	p = ans;
	for (; p != NULL; p = p->next) {
		cout << p->val << " ";
	}

	cin >> c;
}