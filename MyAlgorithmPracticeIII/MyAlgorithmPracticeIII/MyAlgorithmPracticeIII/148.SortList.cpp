// ok : May intend insertion sort... but... 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <regex>
#include <memory>
#include <random>

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
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<ListNode*> v;

        if (head == nullptr) return head;

        ListNode* p = head;
        while (p != nullptr) {
            v.push_back(p);
            p = p->next;
        };

        sort(v.begin(), v.end(), [] (ListNode * l, ListNode * r) {
            return l->val < r->val;
        });

        head = v[0];
        for (int i = 1; i < v.size(); ++i) {
            v[i - 1]->next = v[i];
        }
        v[v.size() - 1]->next = nullptr;

        return head;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> richer = { {1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3} };
    vector<int> quiet = { 3, 2, 5, 4, 6, 1, 7, 0 };

    vector<int> ans = sol.loudAndRich(richer, quiet);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
