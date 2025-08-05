// ok : just use map
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <cmath>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_map<string, int> m;
        vector<string> ans;


        string ss;
        for (int i = 0; i < s.size(); ++i) {
            ss.push_back(s[i]);

            if (m.find(ss) == m.end()) { // not exist
                m[ss]++;
                ans.push_back(ss);
                ss = "";
                continue;
            }
        }
        
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    string s = "abbccccd";

    vector<string> ans = sol.partitionString(s);

    for (auto& it : ans) {
        cout << it << " ";
    }

    std::cin >> c;
}