// Ok...  debug from help of GTP. 
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
    int appendCharacters(string s, string t) {
        int lt = t.size();
        int ls = s.size();

        int idx = 0;
        for (int i = 0; i < lt; ++i) {
            while (s[idx] != t[i]) {
                idx++;
                if (idx == ls) {
                    // conclusion 
                    return lt - i;
                }
            }
            idx++;  // matching 
            if (idx == ls) {
                // conclusion 
                return lt - i - 1;
            }
        }
    
        return 0;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "coaching";
    string t = "coding";

    cout << sol.appendCharacters(s, t);
    cin >> c;
}