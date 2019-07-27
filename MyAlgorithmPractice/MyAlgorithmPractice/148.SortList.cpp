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
	ListNode* mergesort(ListNode* p, ListNode *np, int size) {
		ListNode *m = p;
		if(size <= 1) return p;

		for(int i = 0; i < size/2; ++i) m = m -> next;

		int fs = size / 2;
		int bs = (size % 2 == 1)? size/2 + 1 : size/2;
		p = mergesort(p, m, fs);
		m = mergesort(m, np, bs);

		ListNode *q = p;
		ListNode *h;
		if(q->val < m->val) {
			p = h = q;
			if(q->next != NULL) q = p -> next;
			fs--;
		} else {
			p = h = m;
			if(m->next != NULL) m = m -> next;
			bs--;
		}

		for(int i = 0; i < size-1; ++i) {
			if(fs <= 0) {
				h->next = m; h = m;
				if(m->next != NULL) m = m -> next;
				bs--;
				continue;
			} else if (bs <= 0) {
				h->next = q;h = q;
				if(q->next != NULL) q = q -> next;
				fs--;
				continue;
			}

			if(q->val < m->val) {
				h->next = q;h = q;
				if(q->next != NULL) q = q -> next;
				fs--;
			} else {
				h->next = m;h = m;
				if(m->next != NULL) m = m -> next;
				bs--;
			}
		}
		h->next = np;
		return p;
	}

    ListNode* sortList(ListNode* head) {
		int n = 0;
		ListNode *p = head;

		while(p != NULL) {
			n++;
			p = p -> next;
		}
		p =  mergesort(head, NULL, n);
		return p;
	}
};

int main() {
	Solution sol;
	char c;
//	vector<int> v = { 4, 2, 1, 3 };
	vector<int> v = { 4, 2, 1, 3, 5 };
	ListNode *DummyHeader = new ListNode(-1);
	ListNode *p = DummyHeader;
	for (auto it : v) {
		p->next = new ListNode(it);
		p = p->next;
	}

	DummyHeader->next = sol.sortList(DummyHeader->next);

	p = DummyHeader->next;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	cin >> c;
}
