//  little treaky for debugging
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

class Solution {
public:
	int direction = 1;
	bool next(int m, int n, vector<vector<int>> &map, int &l, int &c) {

		// 1 : right, 2 : down, 3: left, 4: up
		//static int direction = 1;

		// check four direction 
		for (int i = 0; i < 4; ++i) {
			switch (direction) {
			case 1:
				if (c + 1 < n && map[l][c + 1] == -2) {
					c++;
					return true;
				}
				break;
			case 2:
				if (l + 1 < m && map[l + 1][c] == -2) {
					l++;
					return true;
				}
				break;
			case 3:
				if (0 <= c - 1 && map[l][c - 1] == -2) {
					c--;
					return true;
				}
				break;
			case 4:
				if (0 <= l - 1 && map[l - 1][c] == -2) {
					l--;
					return true;
				}
				break;
			}

			direction++;
			if (direction > 4) direction = 1;
		}
		return false;
	}

	vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
		vector<vector<int>> map(m, vector<int>(n, -2));
		ListNode* p = head;
		int l = 0, c = 0;

		direction = 1;
		do {
			if (p == nullptr) {
				map[l][c] = -1;
			}
			else {
				map[l][c] = p->val;
				p = p->next;
			}
		} while (next(m, n, map, l, c) != false);

		return map;
	}
};



int main() {
	char c;

	Solution sol;

	vector<int> head = { 3,0,2,6,8,1,7,9,4,2,5,5,0 };
	vector<vector<int>> map = sol.spiralMatrix(3, 5, &head);


	cin >> c;

}