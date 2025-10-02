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
    string processStr(string s) {

        string ans = "";
        for (auto& it : s) {
            if (it == '*') {
                if (ans.size() > 0) ans.pop_back();
            }
            else if (it == '#') {
                ans += ans;
            }
            else if (it == '%') {
                if (ans.size() > 0) std::reverse(ans.begin(), ans.end());
            }
            else {
                ans.push_back(it);
            }
        }

        return ans;

    }
};

int main() {
    Solution sol;
    char c;
    string s = "*%";

    cout << sol.processStr(s);

    cin >> c;
}
