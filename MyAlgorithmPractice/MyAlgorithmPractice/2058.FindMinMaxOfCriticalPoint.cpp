// Solution is  크게 난의도가 많지 않음... 
// 각각의 플래그를 잘 쓰면 됨.. !! 
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
	bool isCriticalPoints(ListNode *p, int pr_val) {

		if (p->next == NULL) return false;

		if (pr_val < p->val && p->val > p->next->val) return true;
		if (pr_val > p->val && p->val < p->next->val) return true;

		return false;
	}
	vector<int> nodesBetweenCriticalPoints(ListNode* head) {
		int idx = 0; 
		int st_idx = -1, ed_idx = -1, pr_c_idx = -1, pr_val = -1;
		int min = INT_MAX, max = INT_MIN;

		ListNode* p, *q;

		p = head;
		pr_val = p->val;
		p = p->next;
		idx++;

		while (p != NULL) {
			if (isCriticalPoints(p, pr_val)) {
				if (st_idx == -1) {
					st_idx = idx;
				}
				if (pr_c_idx != -1) {  // not first critical point
					if (min > idx - pr_c_idx) min = idx - pr_c_idx;
					ed_idx = idx;
				}
				pr_c_idx = idx;
			}

			pr_val = p->val;
			p = p->next;
			idx++;
		}

		max = ed_idx - st_idx;

		if (ed_idx == -1) return vector<int>({ -1, -1});

		return vector<int>({ min, max });
	}
};

int main() {
	char c;

	Solution sol;

	//	vector<vector<int>> items = { {1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5} };
	//	vector<int> queries = { 1, 2, 3, 4, 5, 6 };

	//	vector<vector<int>> items = { {1, 2}, {1, 2}, {1, 3}, {1, 4}};
	//	vector<int> queries = { 1};

	vector<vector<int>> items = { {193, 732}, {781, 962}, {864, 954}, {749, 627}, {136, 746}, {478, 548}, {640, 908}, {210, 799}, {567, 715}, {914, 388}, {487, 853}, {533, 554}, {247, 919}, {958, 150}, {193, 523}, {176, 656}, {395, 469}, {763, 821}, {542, 946}, {701, 676} };
	vector<int> queries = { 885, 1445, 1580, 1309, 205, 1788, 1214, 1404, 572, 1170, 989, 265, 153, 151, 1479, 1180, 875, 276, 1584 };



	cout << endl;
	//	cout << sol.countHighestScoreNodes(parents) << endl;
		//	cout << "test : " << ans << endl;

	cin >> c;
}