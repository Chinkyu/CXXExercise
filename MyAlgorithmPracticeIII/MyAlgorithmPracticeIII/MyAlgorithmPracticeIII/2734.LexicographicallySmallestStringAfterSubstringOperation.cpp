// ok : exception cases.... 
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
    string smallestString(string s) {
        // find left most substring not contain a
        int l = s.size();

        int st = 0, ed = 0;

        // only one element
        if (l == 1) {
            s[0]--;
            if (s[0] == 'a' - 1) s[0] = 'z';
            return s;
        }


        while (st < l && s[st] == 'a') st++;
        ed = st;

        // for aa -> az case
        if (st == l) {
            s[l - 1] = 'z';
            return s;
        }

        ed = l - 1;
        for (int i = st; i < l; ++i) {
            if (s[i] == 'a') {
                ed = i - 1;
                break;
            }
        }
        //if (ed == st) ed = l - 1;

        //if (st != ed) {
            for (int i = st; i <= ed; ++i) {
                s[i]--;
            }
        //}

        return s;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "ba";
        // "acbbc";
    //"cbabc";
    cout << sol.smallestString(s);

    cin >> c;
}
