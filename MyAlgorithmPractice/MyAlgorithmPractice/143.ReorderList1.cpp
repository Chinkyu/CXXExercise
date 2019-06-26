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
	void reorderList(ListNode* head) {
		ListNode *p, *q;
		ListNode *dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode *ans = NULL;
		if (head == NULL) return;
		int n = 1;

		p = head;
		while (p->next != NULL) {
			p = p->next;
			n++;
		}
		if (n <= 1) return;
		if(n % 2 == 1) {
			q = p = head;
			for(int i = 1; i < n/2; ++i) {
				q = p;
				p = p -> next;
			}
			ans = p->next; //ans->next = NULL;
			p->next = p->next->next;
			ans->next = NULL;

//			q->next = p->next->next;
//			p->next->next = ans;
//			ans = p;
		}


		for(int i = n/2+1; i > 1; --i) {
			p = q= dummyHead;
			for(int j = 1; j < i; ++j) {
				q = p;
				p = p->next;
			}
			q->next = p->next->next;
			p->next->next = ans;
			ans = p;
		}
		head = ans;
	}
};

int main() {
	Solution sol;
	char c;

	vector<int> v = { 1, 2, 3, 4, 5 };

	ListNode *dummyRoot = new ListNode(-1);
	ListNode *q, *p;
	p = q = dummyRoot;
	for (auto it : v) {
		q->next = new ListNode(it);
		q = q->next;
	}

	sol.reorderList(dummyRoot->next);

	p = dummyRoot->next;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}

	cin >> c;
}
