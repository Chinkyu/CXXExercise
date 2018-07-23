//
// ERROR ....
// Answer : No intersection, ERROR: linked structure was modified.
// => Just change value.... => make this error
// => need to find solution that doesn't change value also. 
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
	ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
		// init val for each ListNode
		ListNode *p, *q;

		p = headA;
		while (p != NULL) {
			p->val = 0;
			p = p->next;
		}

		p = headB;
		while (p != NULL) {
			p->val = 0;
			p = p->next;
		}

		p = headA;
		while (p != NULL && p->next != NULL) {
			p->next->val++;
No intersection, ERROR: linked structure was modified.			p = p->next;
		}

		p = headB;
		while (p != NULL && p->next != NULL) {
			p->next->val++;
			if (p->next->val >= 2) return p->next;
			p = p->next;
		}
		return NULL;
	}
};


int main() {
	Solution sol;
	char c;

	cout << "testing...";
	sol.getIntersectionNode(NULL, NULL);
	cin >> c;

}
