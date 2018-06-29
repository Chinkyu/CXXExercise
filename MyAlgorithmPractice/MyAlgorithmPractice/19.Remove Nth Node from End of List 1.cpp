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

// Solution with one iteration...  : Accepted Solution... 
class Solution {
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		int nodeNum = 0;
		int i;
		ListNode *p, *q;

		ListNode dummy(0);
		dummy.next = head;


		p = &dummy;
		q = &dummy;
		while (p->next != NULL) {
			if (--n < 0) {
				q = q->next;
			}
			p = p->next;
		}

		// remove q;
		q->next = q->next->next;

		return dummy.next;
	}
};

// Solution with two iteration... => Timeout.. : XXXX : 
class Solution2 {
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
			q = p->next;
			p->next = p->next->next;
			delete q;
		}

		if (nodeNum == 1) {
			delete head;
			head = NULL;
		}
		//		delete p;

		return head;
	}
};

int main() {
	char c;
	Solution sol;
	ListNode *p, *q;
	ListNode *hd = new ListNode(1);
	hd->next = p = new ListNode(2);
//	p->next = new ListNode(3); p = p->next;
//	p->next = new ListNode(4); p = p->next;
//	p->next = new ListNode(5);
	

	p = sol.removeNthFromEnd(hd, 2);

//	p = hd;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	cin >> c;
}