// ¥‰∫√¿Ω : Binary Search ..

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
#include <functional>

using namespace std;

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& rem) {
        int l = 0, r = rem.size();
        vector<int> map(s.size(), INT_MAX);
        for (int i = 0; i < rem.size(); ++i)
            map[rem[i]] = i;
        while (l < r) {
            int m = (l + r + 1) / 2, j = 0;
            for (int i = 0; i < s.size() && j < p.size(); ++i)
                if (map[i] >= m && s[i] == p[j])
                    ++j;
            if (j == p.size())
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};

// timeout : XXXX : 
class _Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        string m = "(.*)";
        for (auto& it : p) {
            m.push_back(it);
            m.append("(.*)");
        }

        regex pattern(m);
        for (int i = 0; i < removable.size(); ++i) {
            s[removable[i]] = '_';

            if( false == regex_match(s, pattern)) return i;
        }
        
        return removable.size();

    }
};

int main() {
    char c;
    Solution sol;
    string s = "abcacb";
    string p = "ab";
    vector<int> removable = { 3, 1, 0 };

    cout << sol.maximumRemovals(s, p, removable);

    cin >> c;
}