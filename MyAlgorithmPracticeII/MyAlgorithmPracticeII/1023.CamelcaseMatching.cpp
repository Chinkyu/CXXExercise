//  easy : regexp
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
    vector<bool> camelMatch(vector<string>& queries, string pattern) {

        string p("[a-z]*");

        for (auto& it : pattern) {
            p.push_back(it);
            p.append("[a-z]*");
        }
        regex ptn(p);

        vector<bool> ans;
        for (auto& it : queries) {
            smatch matches;
            ans.push_back(std::regex_match(it, matches, ptn));
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector <string> queries = { "FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack" };
    string pattern{ "FB" };

    vector<bool> ans = sol.camelMatch(queries, pattern);

    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}