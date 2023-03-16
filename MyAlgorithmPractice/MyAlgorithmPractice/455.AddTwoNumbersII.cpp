// Stack 가지고 쉽게 풀었음.. !!! 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <map>

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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> sa, sb;

		ListNode *p = l1;
		while (p != nullptr) {
			sa.push(p->val);
			p = p->next;
		}

		ListNode *q = l2;
		while (q != nullptr) {
			sb.push(q->val);
			q = q->next;
		}

		p = nullptr;
		int val = 0, carry = 0;
		while (sa.size() != 0 || sb.size() != 0) {
			val = 0;
			if (sa.size() != 0) {
				val = sa.top();
				sa.pop();
			}

			if (sb.size() != 0) {
				val += sb.top();
				sb.pop();
			}

			val += carry;
			carry = val / 10;
			val = val % 10;

			p = new ListNode(val, p);
		}

		if (carry > 0) p = new ListNode(carry, p);

		return p;
	}
};


int main() {
	char c;

	Solution sol;

	vector<string> nums = { "777", "7", "77", "77" };

	//	string t = "ete";
	//	if (true == sol.isPalandrom(t)) cout << "true" << endl;

	cout << sol.numOfPairs(nums, "7777");

	//cout << sol.minimumSwap(s1, s2);

	cin >> c;
}