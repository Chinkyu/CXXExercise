// ¥‰∫√¿Ω :  Complicate to reverse 
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

class _Solution {
public:
	// Reverse function
	ListNode* reverse(ListNode* head) {
		if (head == NULL)
			return head;

		ListNode* prev = NULL, *forward = NULL;
		while (head != NULL) {
			forward = head->next;
			head->next = prev;
			prev = head;
			head = forward;
		}
		return prev;
	}

	ListNode* reverseEvenLengthGroups(ListNode* head) {
		ListNode* dummy = new ListNode(), *prev = dummy;
		dummy->next = head;

		// Step 1 - determine the length of groups
		for (int len = 1; len < 1e5 && head; len++) {
			ListNode* tail = head, *nextHead;

			// Determining the length of the current group
			// Its maximum length can be equal to len
			int j = 1;
			while (j < len && tail != NULL && tail->next != NULL) {
				tail = tail->next;
				j++;
			}

			// Head of the next group
			nextHead = tail->next;
			if ((j % 2) == 0) {
				// If group size is even then reverse the group and set prev and head
				tail->next = NULL;
				prev->next = reverse(head);
				prev = head;
				head->next = nextHead;
				head = nextHead;
			}
			else {     // If group is odd sized then simply go to the next group
				prev = tail;
				head = nextHead;
			}
		}

		return dummy->next;
	}
};



int main() {
	char c;
	Solution sol;

	pair<int, int> p1, p2;

	string encodedText = "ch   ie   pr";
	cout << sol.decodeCiphertext(encodedText, 3);

	cin >> c;
}