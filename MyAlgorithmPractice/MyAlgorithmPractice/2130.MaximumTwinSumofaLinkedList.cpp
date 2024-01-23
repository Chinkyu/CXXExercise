// easy
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
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
	int pairSum(ListNode* head) {
		deque<int> dq;

		ListNode *p = head;
		do {
			dq.push_back(p->val);
			p = p->next;
		} while (p != nullptr);

		int tmax = 0;
		do {
			int s = dq.back() + dq.front();
			dq.pop_front();
			dq.pop_back();
			tmax = max(tmax, s);
		} while (!dq.empty());

		return tmax;
	}
};

int main() {
	char c;

	Solution sol;
	vector<string> words = { "lc", "cl", "gg" };

	cout << sol.longestPalindrome(words);

	cin >> c;
}