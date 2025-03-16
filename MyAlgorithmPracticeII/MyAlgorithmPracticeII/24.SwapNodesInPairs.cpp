// OK : 

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
#include <functional>

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *pre_p = head, *p = head, * q = head;

        if (p == nullptr) return nullptr;
        q = p->next;
        if (q == nullptr) return head;

        p->next = q->next;
        q->next = p;
        head = q;

        while (p->next != nullptr) {
            pre_p = p;
            p = p->next;
            q = p->next;
            if (q == nullptr) break;


            p->next = q->next;
            q->next = p;
            pre_p->next = q;
        }

        return head;
    }
};

int main() {
    char c;
    Solution sol;

    //    string colors = "abaac";
    //    vector<int> needTime = { 1, 2, 3, 4, 5 };
    string colors = "aabaa";
    vector<int> needTime = { 1, 2, 3, 4, 1 };


    //cout << sol.minCost(colors, needTime);

    cin >> c;
}