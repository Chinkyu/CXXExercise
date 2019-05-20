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
	ListNode* deleteDuplicates(ListNode* head) {
		
		if (head == NULL) return NULL;
		
		ListNode *p = new ListNode(-1); // root node;
		ListNode *q = head;
		ListNode *dummyHeader = p;



		p->next = head;
		q = p->next;
		while (q != NULL && q->next != NULL) {
			bool isSameDetected = false;
			while (q->next != NULL && q->val == q->next->val) {
				// remove q->next
				isSameDetected = true;

				ListNode *d = q->next;
				q->next = q->next->next;
				delete d;
				continue;
			}

			if (isSameDetected == true) {
				p->next = q->next;
				delete q;
				// p should be stay 
			}
			else {
				p = p->next;
			}
			q = p->next;
			//if (q == NULL) return NULL;
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
	vector<int> num = { 1, 2, 2};

	ListNode *root = new ListNode(num[0]);
	ListNode *p = root;
	
	for (int i = 1; i < num.size(); ++i) {
		p ->next = new ListNode(num[i]);
		p = p->next;
	}

	root = sol.deleteDuplicates(root);

	for (p = root; p->next != NULL; p = p -> next) {
		cout << p->val << ",";
	}
	cout << p->val;
	cout << endl;

	cin >> c;
}