// OK : 2 step -> 1step delete mid..  

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
    ListNode* deleteMiddle(ListNode* head) {

        ListNode *p = head, *q = head;
        ListNode* pre_q = q;
        do {
            p = p->next;
            if (p == nullptr) {
                pre_q = q;
                break;
            }
            p = p->next;
            if (p == nullptr) {
                pre_q = q;
                break;
            }

            pre_q = q;
            q = q->next;
        } while (p->next != nullptr);

        // remove q
        if (pre_q->next != nullptr) {
            pre_q->next = pre_q->next->next;
        }
        else {
            return nullptr;
        }
        //delete q;

        return head;
    }
};

int main() {
    char c;
    Solution sol;


    //cout << sol.maximumRemovals(s, p, removable);

    cin >> c;
}