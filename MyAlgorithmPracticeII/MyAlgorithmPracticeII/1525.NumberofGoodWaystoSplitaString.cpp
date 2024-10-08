// easy :  
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
    int numSplits(string s) {
        unordered_map<char, int> lc, rc;

        for (int i = 0; i < s.size(); ++i) {
            rc[s[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            lc[s[i]]++;
            rc[s[i]]--;
            if (rc[s[i]] == 0) {
                rc.erase(s[i]);
            }

            if (lc.size() == rc.size()) ans++;

        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    string s = "aacaba";

    cout << sol.numSplits(s);

    cin >> c;
}