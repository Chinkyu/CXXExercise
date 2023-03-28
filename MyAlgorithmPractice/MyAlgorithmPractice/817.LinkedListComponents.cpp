//쉽게 풀림.. 

#include <iostream>
#include <vector>
#include <unordered_map>
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

class Solution {
public:
	int numComponents(ListNode* head, vector<int>& nums) {
		unordered_map<int, bool> m;

		for (auto it : nums) m[it] = true;

		ListNode *p = head;
		int num = 0;
		int state = 0;   // 0 - not exist state, 1 - exist state
		do {
			if (m.find(p->val) != m.end()) { // exist
				if (state == 0) {  // from not exist
					state = 1;
					num++;
				}
			}
			else {  // not exist
				if (state == 1) {
					state = 0;
				}
			}
			p = p->next;
		} while (p != nullptr);
		return num;
	}
};

int main() {
	char c;

	Solution sol;

	//string s = "(123)";
	//string s = "(0123)";
	string s = "(00011)";
	vector<string> ans = sol.ambiguousCoordinates(s);

	for (auto it : ans) {
		cout << it << endl;
	}

	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}