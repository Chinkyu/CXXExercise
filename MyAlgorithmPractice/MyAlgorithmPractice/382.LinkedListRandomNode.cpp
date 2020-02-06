#include <iostream>
#include <unordered_set>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *h;
	int size = 0;
	/** @param head The linked list's head.
		Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		h = head;
		srand(time(NULL));

		size = 1;
		for (ListNode *p = head; p->next != NULL; p = p->next) size++;
	}

	/** Returns a random node's value. */
	int getRandom() {
		ListNode *p = h;
		int r = rand() % size;
		for (int i = 0; i < r; ++i) {
			p = p->next;
		}
		return p->val;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */