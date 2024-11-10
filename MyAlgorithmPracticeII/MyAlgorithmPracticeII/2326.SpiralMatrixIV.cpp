//  tricky debugging : 
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
    enum direction {
        RIGHT,
        DOWN,
        LEFT,
        UP
    };

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int dir = RIGHT;
        int r = 0, c = 0;
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

        ans[r][c] = head->val;
        ListNode* p = head->next;

        for (int i = 0; i < n * m - 1; ++i) {

            switch (dir) {
            case RIGHT:
                c++;
                if (c == n || (ans[r][c] != INT_MAX)) {
                    c--;
                    r++;
                    dir++;
                }
                break;
            case DOWN:
                r++;
                if (r == m || ans[r][c] != INT_MAX) {
                    r--;
                    c--;
                    dir++;
                }
                break;
            case LEFT:
                c--;
                if (c < 0 || ans[r][c] != INT_MAX) {
                    c++;
                    r--;
                    dir++;
                }
                break;
            case UP:
                r--;
                if (r < 0 || ans[r][c] != INT_MAX) {
                    r++;
                    c++;
                    dir = RIGHT;
                }
                break;
            }

            if (p != nullptr) {
                ans[r][c] = p->val;
                p = p->next;
            }
            else {
                ans[r][c] = -1;
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> hv = { 3,0,2,6,8,1,7,9,4,2,5,5,0 };

    ListNode* head = new ListNode(hv[0]);
    ListNode* p = head;
    for (int i = 1; i < hv.size(); ++i) {
        p->next = new ListNode(hv[i]);
        p = p->next;
    }

    vector<vector<int>> ans = sol.spiralMatrix(3, 5, head);

    for (auto it : ans) {
        for (auto jt : it) {
            cout << jt << " ";
        }
        cout << endl;
    }

    cin >> c;
}