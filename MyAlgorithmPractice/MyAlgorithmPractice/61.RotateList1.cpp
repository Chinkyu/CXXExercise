#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode *end = head;
		int n = 1;

		if (head == NULL) return NULL;

		while (end->next != NULL) {
			n++;
			end = end->next;
		}

		k = k % n;
		if (k == 0) return head;
		ListNode *p = head, *q = head;
		for (int i = 0; i < n - k; ++i) {
			q = p;
			p = p->next;
		}

		end->next = head;
		head = p;
		q->next = NULL;

		return head;
	}
};

int main() {
	Solution sol;
	char c;

	ListNode n1(1), n2(2), n3(3), n4(4), n5(5);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	//ListNode *n = sol.rotateRight(&n1 ,2);
	ListNode *n = sol.rotateRight(&n5, 1);

	ListNode *p = n;
	do {
		cout << p->val << " ";
		p = p->next;
	} while (p != NULL);
	cout << endl;

	cin >> c;
}
