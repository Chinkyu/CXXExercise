// ok..
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* p, * q;

        unordered_map<int, int> m;
        for (auto& it : nums) m[it]++;

        p = q = head;

        // check head
        while (head != nullptr && m[head->val] != 0) {
            p = head;
            head = head->next;
            //delete p;
        }

        p = head;
        q = head;
        while (p != nullptr) {
            if (m[p->val] != 0) {
                q -> next = p->next;
                //p = nullptr;
                delete p;
                p = q;
                continue;
            }

            q = p;
            p = p->next;
        }

        return head;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1, 2, 3 };

    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for (auto it : { 2, 3, 4, 5 }) {
        p->next = new ListNode(it);
        p = p->next;
    }

    ListNode* ans = sol.modifiedList(nums, head);
    p = ans;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }

    cin >> c;
}
