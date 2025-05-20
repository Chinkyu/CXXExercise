// OK : use multi set for one ...   same number multi set.
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
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> lm, rm;
        set<char> ls, rs;
        multiset<int> lns, rns;

        for (auto& it : word1) {
            lm[it]++;
            ls.insert(it);
        }

        for (auto& it : word2) {
            rm[it]++;
            rs.insert(it);
        }

        if (ls != rs) return false;
        if (word1.size() != word2.size()) return false;

        for (auto& it : lm) {
            lns.insert(it.second);
        }

        for (auto& it : rm) {
            rns.insert(it.second);
        }

        if (lns != rns) return false;

        return true;
    }
};

int main() {
    char c;
    Solution sol;

    string word1 = "abc";
    string word2 = "bca";

    cout << sol.closeStrings(word1, word2);

    cin >> c;
}