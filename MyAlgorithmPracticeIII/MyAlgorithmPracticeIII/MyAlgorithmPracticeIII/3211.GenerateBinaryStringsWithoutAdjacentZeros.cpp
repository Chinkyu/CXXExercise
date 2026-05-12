// ok : Not allow double zero 
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

    void traverse(int n, vector<string>& ans, string s, int idx) {

        if (idx >= n) {
            ans.push_back(s);
            return;
        }


        // 0
        if (s[idx - 1] != '0') {
            traverse(n, ans, s + '0', idx + 1);
        }

        // 1
        traverse(n, ans, s + '1', idx + 1);
    }

    vector<string> validStrings(int n) {

        vector<string> ans;

        traverse(n, ans, "0", 1);
        traverse(n, ans, "1", 1);

        return ans;

    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1, 2, 3 };

    vector<string> ans = sol.validStrings(3);
    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
