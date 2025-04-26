//  ok : hint : maintain last character and only remain max occurene
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
#include <set>
#include <list>
#include <regex>
#include <memory>
#include <functional>

using namespace std;


// timeout 
class _Solution {
public:
    string lastNonEmptyString(string s) {

        string bs;
        do {
            unordered_map<char, int> m;
            string ts;
            bs = s;

            for (int i = 0; i < s.size(); ++i) {
                m[s[i]]++;
                if (m[s[i]] == 1) {
                    continue;
                }
                ts.push_back(s[i]);
            }
            s = ts;

        } while (!s.empty());

        return bs;
    }
};

class Solution {
public:
    string lastNonEmptyString(string s) {

        unordered_map<char, int> m;

        string ls;
        int tmax = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            m[s[i]]++;
            if (m[s[i]] == 1) {
                ls.push_back(s[i]);
            }

            tmax = max(tmax, m[s[i]]);

        }

        reverse(ls.begin(), ls.end());

        // finx max
        string ans;
        for (int i = 0; i < ls.size(); ++i) {
            if (m[ls[i]] == tmax) {
                ans.push_back(ls[i]);
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    
    string s = "aabcbbca";

    cout << sol.lastNonEmptyString(s);

    cin >> c;
}