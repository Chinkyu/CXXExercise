// ok : last answer because slow

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
    string clearStars(string s) {

        map<char, int> m;

        string ans = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                if (ans.size() > 0) {
                    char c = m.begin()->first;
                    for (int j = ans.size() - 1; j >= 0; j--) {
                        if (ans[j] == c) {
                            ans.erase(j, 1);
                            break;
                        }
                    }
                    m.begin()->second--;

                    if (m.begin()->second <= 0) {
                        m.erase(c);
                    }
                }
            }
            else {
                m[s[i]]++;
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "aaba*";

    cout << sol.clearStars(s);

    cin >> c;
}