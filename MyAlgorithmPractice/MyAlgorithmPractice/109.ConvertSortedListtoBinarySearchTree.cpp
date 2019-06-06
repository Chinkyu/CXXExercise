#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:

	void inOrder(TreeNode *p) {
		if (p == NULL) return;
		if (p->left != NULL) inOrder(p->left);
		cout << p->val << " ";
		if (p->right != NULL) inOrder(p->right);
	}

	void buildTree(ListNode* head, TreeNode *p) {

		if (head == NULL) return;
		if (head->next == NULL) {
			p->val = head->val;
			return;
		}

		// divide list
		ListNode * lp = head, *lq;
		int lc = 1;
		while(lp->next != NULL) {
			lp = lp->next;
			lc++;
		};

		lp = lq = head;
		for (int i = 0; i < lc / 2; ++i) {
			lq = lp;
			lp = lp->next;
		}


		//p = new TreeNode(lp->val);
		p->val = lp->val;
		lq->next = NULL;
		if (head != NULL) {
			p->left = new TreeNode(0);
			buildTree(head, p->left);
		}
		if (lp->next != NULL) {
			p->right = new TreeNode(0);
			buildTree(lp->next, p->right);
		}

		delete lp;
	}


	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL) return NULL;
		TreeNode* root = new TreeNode(0);

		buildTree(head, root);
		return root;
	}
};

int main() {
	char c;
	Solution sol;
	vector<int> v = { -10, -3, 0, 5, 9 };
	ListNode * head = new ListNode(v[0]);

	ListNode *p = head;
	for (int i = 1; i < v.size(); ++i) {
		p->next = new ListNode(v[i]);
		p = p->next;
	}

	TreeNode *root = sol.sortedListToBST(head);
	sol.inOrder(root);

	cin >> c;
}