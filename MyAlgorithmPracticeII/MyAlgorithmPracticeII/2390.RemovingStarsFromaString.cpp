// easy
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
    string removeStars(string s) {

        deque<char> dq;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                dq.pop_back();
            }
            else {
                dq.push_back(s[i]);
            }
        }

        string ans;
        while (!dq.empty()) {
            ans.push_back(dq.front());
            dq.pop_front();
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    string s = "leet**cod*e";

    cout << sol.removeStars(s);

    cin >> c;
}