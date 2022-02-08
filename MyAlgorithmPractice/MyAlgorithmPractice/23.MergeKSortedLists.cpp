#include <iostream>
#include <vector>

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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int num = lists.size();

		ListNode *head = new ListNode();
		ListNode *hp = head;

		vector<ListNode *> p(num, NULL);

		// initialization pointer 
		for (int i = 0; i < num; ++i) {
			p[i] = lists[i];
		}


	// loop till all p are null 
		bool isAllNull = false;
		do {
			int minIdx = 0, minVal = INT_MAX;
			isAllNull = true;
			for (int i = 0; i < num; ++i) {
				
				// skip null;
				if (p[i] == NULL) continue;

				isAllNull = false;
				if (minVal > p[i]->val) {
					minIdx = i;
					minVal = p[i]->val;
				}
			}

			if (isAllNull == true) break;
			hp->next = new ListNode(minVal, NULL);
			hp = hp->next;

			p[minIdx] = p[minIdx]->next;

		} while (isAllNull != true);
		// itenrate p find min 

		return head->next;
	}

};

int main() {
	char c;
	Solution sol;

	// make lists 
	vector<vector<int>> ll = { {1, 4, 5}, {1, 2, 3}, {2, 6} };
	vector<ListNode *> lst (ll.size(), NULL);
	for (int i = 0; i < ll.size(); ++i) {
		for (auto jt : ll[i]) {
			ListNode *q = new ListNode(jt, lst[i]);
			lst[i] = q;
			cout << jt << " ";
		}
		cout << endl;
	}

	sol.mergeKLists(lst);

	cout << "test" << endl;

	cin >> c;
}