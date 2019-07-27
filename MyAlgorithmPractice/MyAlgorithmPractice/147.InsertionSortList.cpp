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
	ListNode* insertionSortList(ListNode* head) {
		ListNode *p = head, *pre_p = head;

		while (p != NULL) {
			ListNode *q = head, *pre_q = head;
			while (p != q) {
				if (q->val > p->val) {
					if (pre_q != q) {
						pre_p->next = p->next;
						pre_q->next = p;
						p->next = q;
					}
					else {
						pre_p->next = p->next;
						head = p;
						p->next = q;
					}
					break;
				}
				pre_q = q;
				q = q->next;
			}

			if (p == pre_p->next) {
				pre_p = p;
				p = p->next;
			}
			else {
				p = pre_p->next;
			}
		}
		return head;
	}
};

int main() {
	Solution sol;
	char c;
	//vector<int> v = { 4, 2, 1, 3 };
	vector<int> v = { -1, 5, 3, 4, 0 };
	ListNode * root = new ListNode(-1);

	ListNode *p = root;
	for (auto at : v) {
		p->next = new ListNode(at);
		p = p->next;
	}

	root->next = sol.insertionSortList(root->next);

	for (ListNode *p = root->next; p != NULL; p = p->next) {
		cout << p->val << " ";
	}
	cout << endl;

	cin >> c;
}