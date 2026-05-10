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


//:: ckkang : 이게 맞는 답인것 같다.. 
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k == 1) return 1;

        // Numbers made of only 1s can never be divisible by 2 or 5
        if (k % 2 == 0 || k % 5 == 0) return -1;

        int rem = 0;
        for (int i = 1; rem <= k; i++) {
            rem = (rem * 10 + 1) % k;
            if (rem == 0) return i;
        }
        return -1;
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
