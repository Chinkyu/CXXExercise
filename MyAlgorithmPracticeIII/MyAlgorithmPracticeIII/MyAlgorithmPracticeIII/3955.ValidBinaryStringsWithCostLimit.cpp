// ok... with recursive... 
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
#include <random>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<string> ans;
    int gk = 0;
    void traverse(string s, int n, int l, int cost) {

        char clast = (s.size() == 0)? '0':  *s.rbegin();
        if (l == n) {
            ans.push_back(s);
            return;
        }

        // zero
        traverse(s + '0', n, l + 1, cost);

        // one
        if (clast == '0' && cost + l <= gk) {   // only last is 0 do 1
            traverse(s + '1', n, l + 1, cost + l);
        }
    }


    vector<string> generateValidStrings(int n, int k) {
        ans.clear();
        gk = k;

        traverse("", n, 0, 0);
        return ans;
    }
};

int main() {
    char c;

    Solution sol;

    vector<string> ans = sol.generateValidStrings(3, 1);

    for (auto& it : ans) {
        cout << it << endl;
    }

    cin >> c;
}
