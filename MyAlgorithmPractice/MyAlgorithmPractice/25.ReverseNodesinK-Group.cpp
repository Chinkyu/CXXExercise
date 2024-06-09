//  ¥‰∫√¿Ω 
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
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* prev = NULL, * curr = head, * start = head;
		int count = 0, totalcount = 0;

		// Create a dummy node to serve as the head of the final list
		ListNode* dummy = new ListNode(0);
		ListNode* end = dummy;

		// Count the total number of nodes in the list
		int n = 0;
		ListNode* temp = head;
		while (temp != nullptr)
		{
			n++;
			temp = temp->next;
		}
		while (curr != nullptr)
		{
			// Reversing 
			ListNode* nxt = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nxt;
			count++;
			totalcount++; //keep track of num of nodes processed

			// If we have reversed k nodes, we link the reversed group to the final list
			if (count == k)
			{
				count = 0; // Reset count if k elements are reached
				end->next = prev; // This will be the first element of reversed group
				end = start;
				start->next = curr; // Linking the start of reversed group to rest of the list
				start = curr;
				prev = NULL;

				// If there are less than k nodes left, we break the loop
				if (n - totalcount < k) break;
			}
		}
		return dummy->next;
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


	ListNode* ans = sol.reverseKGroup(h, 2);

	do {
		cout << p->next << " ";
		p = p->next;
	} while (p != nullptr);


	//cout << "test" << endl;

	cin >> c;
}