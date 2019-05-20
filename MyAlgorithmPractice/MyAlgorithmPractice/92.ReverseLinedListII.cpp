#include <iostream>
#include <vector>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//  m, n  을 값으로 보고 푼 해답..... 
 class Solution2 {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode *p, *q;
		ListNode *dummyNode = new ListNode(-1);
		dummyNode->next = head;

		if (m == n) return head;

		// find m(p == m)
		p = head; q = dummyNode;
		while (p != NULL && p->val != m) {
			q = p;
			p = p->next;
		}

		if (p == NULL) return head;

		ListNode *ps = q;
		ListNode *e = p;
		// find n
		while (p != NULL && p->val != n) {
			ListNode *tmp = p->next;
			p->next = q;
			q = p;
			p = tmp;
		}
		if (p == NULL) return head;

		e->next = p->next;
		ps->next = p;
		p->next = q;

		head = dummyNode->next;
		delete dummyNode;
		return head;
	}
};

 //  m, n  은  index 
 class Solution {
 public:
	 ListNode* reverseBetween(ListNode* head, int m, int n) {
		 ListNode *p, *q;
		 ListNode *dummyNode = new ListNode(-1);
		 dummyNode->next = head;

		 if (m == n) return head;

		 // find m(p == m)
		 p = head; q = dummyNode;
		 //while (p != NULL && p->val != m) {
		 for(int i = 1; i < m; ++i) {
			 if (p == NULL) return head;
			 q = p;
			 p = p->next;
		 }

		 ListNode *ps = q;
		 ListNode *e = p;
		 // find n
		 //while (p != NULL && p->val != n) {
		 for (int i = m; i < n; ++i) {
			 if (p == NULL) return head;
			 ListNode *tmp = p->next;
			 p->next = q;
			 q = p;
			 p = tmp;
		 }
		 

		 e->next = p->next;
		 ps->next = p;
		 p->next = q;

		 head = dummyNode->next;
		 delete dummyNode;
		 return head;
	 }
 };

 void main() {
	 char c;
	 Solution sol;

	 //vector<int> num = { 1, 2, 3, 4, 5};
	 //vector<int> num = { 5 };
	 vector<int> num = { 1, 2, 3 };

	 ListNode *root = new ListNode(num[0]);
	 ListNode *p = root;

	 for (int i = 1; i < num.size(); ++i) {
		 p->next = new ListNode(num[i]);
		 p = p->next;
	 }

	 root = sol.reverseBetween(root, 1,2);

	 p = root;
	 while (p != NULL) {
		 cout << p->val << ",";
		 p = p->next;
	 }
	 cout << endl;

	 cin >> c;

}