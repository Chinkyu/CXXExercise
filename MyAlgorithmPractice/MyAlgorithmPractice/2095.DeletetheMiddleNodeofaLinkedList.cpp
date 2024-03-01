// easy
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
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
	ListNode* deleteMiddle(ListNode* head) {
		int l = 1;

		ListNode* p = head;
		while (p->next != nullptr) {
			p = p->next;
			l++;
		}

		if (l == 1) return nullptr;

		//l = (l % 2 == 1) ? (l+ 1)/2 : 1/2;
		l /= 2;

		p = head;
		for (int i = 0; i < l- 1; ++i) {
			p = p->next;
		}

		ListNode *q = p->next;

		p->next = p->next->next;

		delete q;

		return head;
	}
};


int main() {
	char c;

	Solution sol;

	vector<int> nums = { 20,17,0,2,7 }; // { 1, 5, 5, 5, 4 };

	cout << sol.largestEvenSum(nums, 2);

	cin >> c;
}