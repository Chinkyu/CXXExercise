// 스텍 가지고.. 쉽게 풀림... 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

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
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
	ListNode* plusOne(ListNode* head) {
		stack<ListNode *> s;

		ListNode *p = head;
		s.push(p);
		while (p->next != nullptr) {
			p = p->next;
			s.push(p);
		}

		p->val++;

		p = s.top();
		s.pop();
		while (s.size() > 0 && p->val >= 10) {
			int over = p->val / 10;
			p->val = p->val % 10;

			p = s.top();
			p->val += over;
			s.pop();
		}

		// if last p->val
		if (p->val >= 10) {
			int over = p->val / 10;
			p->val = p->val % 10;
			ListNode *q = new ListNode(over, p);
			head = q;
		}

		return head;
	}
};

int main() {
	char c;
	Solution sol;

	string s = "01101110"; //  "011010";
	cout << sol.canReach(s, 2, 3);

	cin >> c;
}