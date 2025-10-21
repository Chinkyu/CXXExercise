// easy : count , remainder  make chunk
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode*> ans;
        if (head == nullptr) {
            for (int i = 0; i < k; ++i) {
                ans.push_back(nullptr);
            }
            return ans;
        }

        int cnt = 1;
        ListNode* p = head;
        while (p->next != nullptr) {
            cnt++;
            p = p->next;
        }

        int num = cnt / k;
        int rem = cnt % k;

        p = head;
        for (int i = 0; i < rem; ++i) {
            ListNode* t = p;
            // num + 1 size
            for (int j = 0; j < num + 1 - 1; ++j) {
                p = p->next;
            }
            ListNode* q = p;
            p = p->next;
            q->next = nullptr;
            ans.push_back(t);
        }

        for (int i = rem; i < k; ++i) {
            ListNode* t = p;
            // num size
            if (num == 0) {
                ans.push_back(nullptr);
            }
            else {
                for (int j = 0; j < num - 1; ++j) {
                    p = p->next;
                }
                ListNode* q = p;
                p = p->next;
                q->next = nullptr;
                ans.push_back(t);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    char c;
    vector<vector<int>> customers = { {1, 2},{2, 5},{4, 3} };
    cout << sol.averageWaitingTime(customers);


    cin >> c;
}
