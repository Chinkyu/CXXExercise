// This is comes from Help...
// Great Code.. 

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
	ListNode *detectCycle(ListNode *head) {
		ListNode *p, *q;

		if (head == NULL) return NULL;

		p = q = head;
		while (p && (p = p->next)) {
			// Has a loop been found.
			if ((p = p->next) == (q = q->next)) {
				// Move advance head and fast by a single step at a time. 
				// When they meet, it is the start of the cycle.
				while (p != head) {
					p = p->next;
					head = head->next;
				}
				return head;
			}
		}
		return NULL;
	}

};

int main() {
	char c;
	Solution sol;

	ListNode *head = new ListNode(3);


	cout << "check linked list cycle";
//	cout << "Has Cycle" << sol.hasCycle(head);



	cin >> c;
}