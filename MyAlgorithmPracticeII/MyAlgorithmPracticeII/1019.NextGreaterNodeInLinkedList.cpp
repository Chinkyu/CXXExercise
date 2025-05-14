//  see answer : use stack ??   
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


// timeout 
class _Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* p = head;
        ListNode* q = p;

        vector<int> ans;

        map<int, vector<int>> m, tm;
        int idx = 0;
        while (p != nullptr) {
            m[p->val].push_back(idx);
            ans.push_back(0);

            tm = m;
            for (auto it : m) {
                if (it.first < p->val) {
                    for (auto jt : it.second) {
                        ans[jt] = p->val;
                    }
                    tm.erase(it.first);
                }
                else {
                    break;
                }
            }
            m = tm;
            p = p->next;
            idx++;
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res, stack;
        for (ListNode* node = head; node; node = node->next) {
            while (stack.size() && res[stack.back()] < node->val) {
                res[stack.back()] = node->val;
                stack.pop_back();
            }
            stack.push_back(res.size());
            res.push_back(node->val);
        }
        for (int i : stack) res[i] = 0;
        return res;
    }
};

int main() {
    char c;
    Solution sol;
    ListNode* root;

    root = new ListNode(2);
    root->next = new ListNode(7);
    root->next->next = new ListNode(4);
    root->next->next->next = new ListNode(3);
    root->next->next->next->next = new ListNode(5);

    vector<int> ans = sol.nextLargerNodes(root);

    for (auto &it : ans) {
        cout << it << " ";
    }


    cin >> c;
}