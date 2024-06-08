// OK
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
#include <regex>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        string mp;
        int l = p.size();

        for (int i = 0; i < l; ++i) {
            if (p[i] == '.') {
                if (i + 1 < l && p[i + 1] == '*') {
                    mp.append("[a-z]*");
                    i++;
                }
                else {
                    mp.append("[a-z]");
                }
            }
            else if (p[i] == '*') {
                if (p[i - 1] == '*') continue;  // ignore continuous '*'

                char c = *mp.rbegin();
                mp.pop_back();
                mp.push_back('[');
                mp.push_back(c);
                mp.append("]*");
            }
            else mp.push_back(p[i]);

        }

        regex re(mp);
        cmatch m;

        return regex_match(s, re);
    }
};

int main() {
    char c;
    Solution sol;

    string s = "ab";
    string p = ".*";
    cout << sol.isMatch(s, p);
    cin >> c;
}