// ok : 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
    bool checkInclusion(string s1, string s2) {
        int l = s1.size();
        unordered_map<char, int> s1m, s2m;

        if (s1.size() > s2.size()) return false;

        for (auto& it : s1) s1m[it]++;

        // first l lendth s2m
        for (int i = 0; i < l; ++i) s2m[s2[i]]++;
        if (s1m == s2m) return true;

        for (int i = 0; i < s2.size() - l; ++i) {
            s2m[s2[i]]--;
            if (s2m[s2[i]] == 0) s2m.erase(s2[i]);
            s2m[s2[i + l]]++;

            if (s1m == s2m) return true;
        }

        return false;
    }
};

int main() {
    Solution sol;
    char c;

    string s1 = "a";
    string s2 = "ab";

    cout << sol.checkInclusion(s1, s2);

    cin >> c;
}
