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


class Solution_False1 {
public:
	bool hasCycle(ListNode *head) {
		ListNode *p, *q;

		if (head == NULL) return false;

		p = q = head;
		while (p->next != NULL) {
			if (q->next != NULL) q = q->next; else return false;

			if (p->next != NULL) p = p->next; else return false;
			if (p->next != NULL) p = p->next; else return false;

			if (p == q && p != NULL) return true;
		}
		return false;
	}
};

int main() {
	char c;
	Solution sol;

	ListNode *head = new ListNode(3);


	cout << "check linked list cycle";
	cout << "Has Cycle" << sol.hasCycle(head);



	cin >> c;
}