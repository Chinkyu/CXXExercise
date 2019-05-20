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
	ListNode* partition(ListNode* head, int x) {
		ListNode *dummyHeader = new ListNode(x-1);
		dummyHeader->next = head;

		// step forward p 
		ListNode *pivot = dummyHeader;
		while (pivot->next != NULL && pivot->next->val < x) pivot = pivot->next;

		ListNode *q = pivot->next, *p = pivot;
		while (q != NULL) {
			if (x <= q->val) {
				p = q;
				q = q->next;
			}
			else {
				// move q to after p
				p->next = q->next;
				q->next = pivot->next;
				pivot->next = q;

				pivot = q;
				q = p->next;
			}
		}

		head = dummyHeader->next;
		delete dummyHeader;
		return head;
	}
};

int main() {
	Solution sol;
	char c;

	//vector<int> num = { 1, 2, 3, 3, 4, 4, 5 };
	//vector<int> num = { 1, 1, 1, 2, 3};
	vector<int> num = { 1, 4, 3, 2, 5, 2 };
	//vector<int> num = { 1, 4, 3, 2, 5, 2 };

	ListNode *root = new ListNode(num[0]);
	ListNode *p = root;

	for (int i = 1; i < num.size(); ++i) {
		p->next = new ListNode(num[i]);
		p = p->next;
	}

	root = sol.partition(root, 2);

	for (p = root; p->next != NULL; p = p->next) {
		cout << p->val << ",";
	}
	cout << p->val << ",";

	cin >> c;
}