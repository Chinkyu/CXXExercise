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
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		int nodeNum = 0;
		int i;
		ListNode *p, *q;

		p = head;
		for (i = 0; p != NULL; p = p->next, ++i) {

		}
		nodeNum = i;
		p = head;
		for (i = 0; i < nodeNum - n - 1; i++) {
			p = p->next;
		}

		// remove p
		if (p->next != NULL) {
			p->next = p->next->next;
		}

		if (nodeNum == 1) {
			p = NULL;
		}
		//		delete p;

		return head;
	}
};


int main() {
	Solution sol;
	ListNode lh = ListNode(1);

	sol.removeNthFromEnd(&lh, 1);
}