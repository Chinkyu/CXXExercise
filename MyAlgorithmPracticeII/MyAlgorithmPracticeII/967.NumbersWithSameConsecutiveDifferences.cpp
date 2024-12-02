//  easy : 
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
    set<string> tset;

    void traverse(string s, int n, int i, int k) {
        if (s.size() == n) {
            tset.insert(s);
            return;
        }

        char c = s[s.size() - 1];

        if ('0' <= c - k) {
            s.push_back(c - k);
            traverse(s, n, i + 1, k);
            s.pop_back();
        }
        if (c + k <= '9') {
            s.push_back(c + k);
            traverse(s, n, i + 1, k);
            s.pop_back();
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        tset.clear();

        for (int i = 1; i <= 9; ++i) {
            string s;
            s.push_back(i + '0');
            traverse(s, n, 1, k);
        }
        
        vector<int> ans;
        for (auto& it : tset) {
            ans.push_back(stoi(it));
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> ans = sol.numsSameConsecDiff(2, 1);

    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}