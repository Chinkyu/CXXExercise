//  easy
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>
#include <cmath>

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
	ListNode* mergeNodes(ListNode* head) {
		ListNode *p, *q;

		head = head->next;
		p = head;
		q = head->next;
		

		while (p != nullptr) {
			q = p->next;
			if (q->val == 0) {
				p->next = q->next;
				delete q;

				p = p->next;
			}
			else {
				p->val += q->val;
				p->next = q->next;
				delete q;
			}	
		}
		return head;
	}
};


int main() {
	char c;

	Solution sol;

	string s = "robnsdvpuxbapuqgopqvxdrchivlifeepy";

	cout << sol.repeatLimitedString(s, 2);

	cin >> c;

}