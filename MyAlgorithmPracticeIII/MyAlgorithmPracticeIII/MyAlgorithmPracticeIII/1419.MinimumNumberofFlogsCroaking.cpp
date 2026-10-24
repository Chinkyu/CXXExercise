// see answer :  c  and k check 
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

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int cnt[5] = {}, frogs = 0, max_frogs = 0;
        for (auto ch : croakOfFrogs) {
            auto n = string("croak").find(ch);
            ++cnt[n];
            if (n == 0)
                max_frogs = max(max_frogs, ++frogs);
            else if (--cnt[n - 1] < 0)   //:: 여기에 매직이 있음.... 
                return -1;
            else if (n == 4)
                --frogs;
        }
        return frogs == 0 ? max_frogs : -1;
    }
};

int main() {
    char c;
    Solution sol;

    string croakOfFrogs = "croakcrook";

    cout << sol.minNumberOfFrogs(croakOfFrogs);

    cin >> c;
}
