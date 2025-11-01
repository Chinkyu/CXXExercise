// see answer : find connecte group and sort
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
    int find(vector<int>& ds, int i) {
        return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> ds(s.size(), -1);
        vector<vector<int>> m(s.size());
        for (auto& p : pairs) {
            auto i = find(ds, p[0]), j = find(ds, p[1]);
            if (i != j)
                ds[j] = i;
        }
        for (auto i = 0; i < s.size(); ++i)
            m[find(ds, i)].push_back(i);
        for (auto& ids : m) {
            string ss = "";
            for (auto id : ids)
                ss += s[id];
            sort(begin(ss), end(ss));
            for (auto i = 0; i < ids.size(); ++i)
                s[ids[i]] = ss[i];
        }
        return s;
    }
};

int main() {
    Solution sol;
    char c;

    sol.combine(4, 2);

    cin >> c;
}
