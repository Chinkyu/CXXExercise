//  tricky 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <regex>
#include <memory>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

	ListNode * reverse(ListNode* s, int k) {

		ListNode* end = nullptr, * ol = nullptr;
		ListNode* p, * q = nullptr, * r;

		// check k number
		p = s;
		for (int i = 0; i < k; ++i) {
			if (p == nullptr) return nullptr;
			p = p->next;
		}

		p = s;
		end = s;
		r = nullptr;
		for (int i = 0; i < k; ++i) {
			q = p->next;
			p->next = r;
			r = p;
			p = q;
		}

		end->next = p;
		s = r;
		return s;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {

		ListNode* l = nullptr, * p_last = nullptr;
		ListNode* p, * q, * r;
		ListNode* ans = nullptr;
		
		ans = reverse(head, k);

		if (ans == nullptr) return head;

		p = r = ans;
		for (int i = 0; i < k; ++i) {
			r = p;
			p = p->next;
		}
		
		while (p = reverse(p, k)) {
			r->next = p;
			for (int i = 0; i < k; ++i) {
				r = p;
				p = p->next;
			}
		}

		return ans;
	}
};

class _Solution {
public:

	bool reverse(ListNode* s, ListNode* l, int k) {

		ListNode* end = nullptr, *ol = nullptr;
		ListNode* p, *q = nullptr, * r;

		// check k number
		p = s;
		for (int i = 0; i < k-1; ++i) {
			if (p == nullptr) return false;
			p = p->next;
		}

		p = s;
		end = s;
		r = nullptr;
		for (int i = 0; i < k; ++i) {
			q = p->next;
			p->next = r;
			r = p;
			p = q;
		}

		end->next = p;
		s = r;
		l = end;
		return true;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {

		ListNode* l = nullptr, *p_last = nullptr;

		ListNode* p, * q;
		if (!reverse(head, l, k)) return head;

		p = l->next;
		p_last = l;
		while (reverse(p, l, k)) {
			p_last->next = p;
			p = l->next;
		}

		return head;
	}
};


int main() {
	char c;
	Solution sol;

	// make lists 
	vector<int> v = { 1, 2, 3, 4, 5 };
	ListNode* h = new ListNode(v[0]);

	ListNode* p = h;
	for (int i = 1; i < v.size(); ++i) {
		p->next = new ListNode(v[i]);
		p = p->next;
	}


	ListNode* ans = sol.reverseKGroup(h, 3);

	p = ans;
	do {
		cout << p->val << " ";
		p = p->next;
	} while (p != nullptr);


	//cout << "test" << endl;

	cin >> c;
}