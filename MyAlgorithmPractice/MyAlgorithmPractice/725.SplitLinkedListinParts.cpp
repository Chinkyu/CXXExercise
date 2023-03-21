// 개수가 큰것에서 작은것으로 내려가야 한다는것이.. 잘 안되어서....
// 반대로 했다가 시간을 좀 잡아 먹음... 나머지는..  OK


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

// toRemove format : direction(1 horizental, 2 virtical),  h_index, vstar_index, vend_index)

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
	vector<ListNode*> splitListToParts(ListNode* head, int k) {
		ListNode * p = head;
		int count = 0;
		while (p != nullptr) {
			count++;
			p = p->next;
		}

		vector<ListNode*> ans(k, nullptr);
		// if count <= k : contain only one 
		if (count <= k) {
			p = head;
			for (int i = 0; i < count; ++i) {
				if (p != nullptr) {
					ans[i] = p;
					p = p->next;
					ans[i]->next = nullptr;
				}
				else {
					break;
				}
			}
		}
		else {
			int remain = count;

			// generate count array
			vector<int> c_arr(k, 0);
			for (int i = k; i > 0; --i) {
				int rnum = round(remain / i);
				c_arr[k - i] = rnum;
				remain -= rnum;
			}
	
			reverse(c_arr.begin(), c_arr.end());

			p = head;
			for (int i = 0; i < k; ++i) {
				ans[i] = p;
				for (int j = 0; j < c_arr[i] - 1; ++j) {
					p = p->next;
				}
				
				ListNode * q = p;
				p = p->next;
				q->next = nullptr;
			}
		}
		return ans;
	}

	void splitListToParts(int num, int k) {
		int remain = num;
		for (int i = k; i > 0; --i) {
			int rnum = round(remain / i);

			cout << " " << rnum;

			remain -= rnum;
		}


	}
};


int main() {
	char c;

	Solution sol;

	sol.splitListToParts(325, 10);
	//cout << sol.minimumSwap(s1, s2);

	cin >> c;
}