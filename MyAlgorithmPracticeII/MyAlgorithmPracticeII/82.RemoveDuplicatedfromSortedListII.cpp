// ok 
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <cmath>
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* r = head;
        ListNode* p = head;
        ListNode* q = p;

        while (p != nullptr) {
            q = p->next;
            bool is_duplicated = false;
            while (q != nullptr && p->val == q->val) {
                p->next = q->next;
                ListNode* t = q;
                q = q->next;
                delete t;
                is_duplicated = true;
            }

            if (is_duplicated) {
                if (p == head) {
                    r = head = p->next;
                    
                }
                else {
                    r->next = p->next;
                }
                ListNode* t = p;
                p = p->next;
                delete t;
                continue;
            }

            r = p;
            p = p->next;

        }
        return head;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<string>> orders = { {"David", "3", "Ceviche"}, {"Corina", "10", "Beef Burrito"}, {"David", "3", "Fried Chicken"}, {"Carla", "5", "Water"}, {"Carla", "5", "Ceviche"}, {"Rous", "3", "Ceviche"} };

    vector<vector<string>> ans = sol.displayTable(orders);

    for (auto& it : ans) {
        for (auto& jt : it) {
            cout << jt << " ";
        }
    }

    std::cin >> c;
}