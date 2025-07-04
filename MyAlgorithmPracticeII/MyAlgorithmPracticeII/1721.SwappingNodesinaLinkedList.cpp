// ²Ç¼ö..... ok 
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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> v;
        
        ListNode* p = head;
        v.push_back(p);

        while (p->next != nullptr) {
            p = p->next;
            v.push_back(p);
        }

        int l = v.size();

        // v[k-1] <-> v[l-k]
        int tval = v[l - k]->val;
        v[l - k]->val = v[k - 1]->val;
        v[k - 1]->val = tval;
/*
        if (k == 1) {
            v[l - k]->next = v[0];
            v[0]->next = nullptr;

            v[l - k - 1]->next = v[0];
            head = v[l - k];
        }
        else {
            v[l - k]->next = v[k - 1 + 1];
            v[k - 1]->next = v[l - k + 1];
            v[l - k - 1]->next = v[k - 1];
            v[k - 1 - 1]->next = v[l - k];
        }
*/
        return head;
    }
};

int main() {
    char c;
    Solution sol;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << sol.swapNodes(head, 2);

    cin >> c;
}