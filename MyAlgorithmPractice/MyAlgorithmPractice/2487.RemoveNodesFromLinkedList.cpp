// 답봤음  - 이해는 나중에.. 
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


//  스택으로 풀어야 되다네... ㅠㅠ
class Solution {
public:
	ListNode* removeNodes(ListNode* head) {
		vector<int> arr;
		ListNode *p = head, *q = nullptr;
		while (p) {
			arr.push_back(p->val); // store linklist in array
			p = p->next;
		}
		stack<pair<int, int>> st;
		for (int i = arr.size() - 1; i >= 0; i--) {
			if (st.empty()) {
				st.push({ arr[i],1 }); // for last element there is no greater element to right of it
			}
			else {
				if (st.top().first > arr[i]) { // if there is greater element to right then in pair put -1 with max till element
					st.push({ st.top().first,-1 });
				}
				else {
					st.push({ arr[i],1 }); // if current is max till now then put it with 1
				}
			}
		}
		p = head;
		// which ever has 1 means it has no greater element to right
		while (st.size()) {
			if (st.top().second == 1) {
				p->val = st.top().first;
				q = p; // q stores previous pointer
				p = p->next;
			}
			st.pop();
		}
		q->next = nullptr;
		return head;
	}
};


class Solution2 {
public:
	ListNode* removeNodes(ListNode* head) {
		// find max and last
		ListNode * max, *last, *p, *q;
		ListNode *pre_last = nullptr;
		max = last = p = head;
		q = p->next;


		// find last and remove all
		while (head != pre_last) {
			// find last  ==> merged with previous 
			//last = head;
			//while (last->next != pre_last) last = last->next;
			
			// remove all smaller than last
			p = q = head;
			while (last != nullptr && q != last) {
				if (q->next == pre_last) last = q;

				if (q->val < last->val) {
					if (q == head) {
						head = q->next;
						p = q = head;
					}
					else {
						p->next = q->next;
						q = p->next;
						//	free(q);
					}
				}
				else {
					p = q;
					q = p ->next;
				}
			}
			pre_last = last;
		}

		return head;
	}
};

//  타임아웃 
class Solution {
public:
	ListNode* removeNodes(ListNode* head) {
		// find max and last
		ListNode * tmax, *last, *p, *q;
		ListNode *nxt_last = nullptr, *pre_last = nullptr;
		tmax = last = p = head;
		int tmax_val = 0;
		q = p->next;

		last = head;
		while (last->next != nullptr) {
			if (last->val > tmax_val) {
				tmax = last; tmax_val = last->val;
			}
			last = last->next;
		}

		// remove first
		p = q = head;
		while (q != tmax) {
		//	if (q == head) {
				head = q->next;
				delete q;
				p = q = head;
		//	}
		}

		// find last and remove all
		while (head != last) {
			// find last  ==> merged with previous 

			nxt_last = nullptr;
			// remove all smaller than last
			p = q = head;
			while (last != nullptr && q != last) {
				if (q->val < last->val) {
					if (q == head) {
						head = q->next;
						delete q;
						p = q = head;
					}
					else {
						p->next = q->next;
						delete q;
						q = p->next;
					}
				}
				else {
					p = q;
					q = p->next;
				}

				if (p->next == last) nxt_last = p;

			}
			if (nxt_last == nullptr || last == head) break;
			last = nxt_last;
		}

		return head;
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> nums = { 6,-6,-3,3,1,5,-4,-3,-2,-3,4,-1,4,4,-2,6,0 };

	cout << sol.makePrefSumNonNegative(nums);

	cin >> c;
}