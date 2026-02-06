// ok : use stack
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
#include <chrono>
#include <iterator>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        ListNode* p = l1;
        do {
            s1.push(p->val);
            p = p->next;
        } while (p != nullptr);

        p = l2;
        do {
            s2.push(p->val);
            p = p->next;
        } while (p != nullptr);


        p = nullptr;
        int carry = 0;
        while(s1.size() > 0 || s2.size() > 0 || carry > 0) {
            int v1 = 0, v2 = 0;
            if (s1.size() > 0) {
                v1 = s1.top();
                s1.pop();
            }

            if (s2.size() > 0) {
                v2 = s2.top();
                s2.pop();
            }

            int sum = v1 + v2 + carry;
            carry = sum / 10;
            
            p = new ListNode(sum % 10, p);
        }

        return p;

    }
};

int main() {
    char c;
    Solution sol;

    vector<string> garbage = { "G", "M" };
    vector<int> travel = { 1 };

    cout << sol.garbageCollection(garbage, travel);


    cin >> c;
}
