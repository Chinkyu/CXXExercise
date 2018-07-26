// From comment - It is good.... 
/*The solution is based on 142. Linked List Cycle II.
The Basic idea is make the first list(headA) a circle by link the end to the beginning.If there is a intersection, then there must be a circle in listB.The start pointer of the circle is the intersection pointer.Therefore, this question becomes 142. Linked List Cycle II.All you need to do is to find the start pointer of the circle.
Don't forget to break the circle when the algorithm are finished.


class Solution {
public:
	ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr)
			return nullptr;
		//First: make a circle
		ListNode* end = headA;
		while (end->next != nullptr) end = end->next;
		end->next = headA;

		//Second: Copy the code of Question 142: Linked List Cycle II
		ListNode* res = yourSolutionOfQuestion142(headB);

		//Third: Break the circle.
		end->next = nullptr;

		return res;

	}
};
*/
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
	
	ListNode * detectCycle(ListNode *head) {
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

	ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *p, *q;

		if (headA == NULL || headB == NULL) return NULL;

		p = headA;
		while (p->next != NULL) p = p->next;
		p->next = headA;

		q = detectCycle(headB);

		// Back p->next to NULL
		p->next = NULL;
		
		return q;
	}

};

int main() {
	Solution sol;
	char c;

	cout << "testing...";
	sol.getIntersectionNode(NULL, NULL);
	cin >> c;

}

#endif