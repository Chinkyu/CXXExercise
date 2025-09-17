// ok :
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
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<int> c(3, 0);

        // count a, b, c
        for (auto& it : s) {
            c[it - 'a']++;
        }

        // check a,b ,c same
        if (c[0] != c[1] && c[1] != c[2]) return false;

        string cs;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'c') {
                int csl = cs.size();
                if (csl < 2) return false;
                if (cs[csl - 2] != 'a' || cs[csl - 1] != 'b') return false;
                cs.pop_back();
                cs.pop_back();
                continue;
            }
            cs.push_back(s[i]);
        }

        if (cs.size() != 0) return false;
        return true;
    }
};

int main() {
    char c;
    Solution sol;
    string s = "abcabcababcc";

    cout << sol.isValid(s);

    cin >> c;
}