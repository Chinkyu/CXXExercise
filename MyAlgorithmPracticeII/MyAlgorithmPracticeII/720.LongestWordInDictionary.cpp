// skip : 문제이해가 문제인지.. 이상해서 skip.. !! 
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
    string longestWord(vector<string>& words) {
        map<string, int> m;
        sort(words.begin(), words.end(), [](string l, string r) {
            return l.size() > r.size();
            });

        m[words[0]] = 1;

        for (int i = 1; i < words.size(); ++i) {
            bool isExist = false;
            for (auto& it : m) {
                if (it.first.compare(0, words[i].size(), words[i]) == 0) {
                    isExist = true;
                    m[it.first]++;
                }
            }
            if (isExist == false) m[words[i]] = 1;
        }

        int tmax = 0;
        for (auto& it : m) {
            tmax = max(tmax, it.second);
        }

        vector<string> ts;
        for (auto& it : m) {
            if (it.second == tmax) ts.push_back(it.first);
        }

        sort(ts.begin(), ts.end(), [](string l, string r) {
            if (l.size() == r.size()) return l < r;
            return l.size() > r.size();
            });

        if (ts.size() == 0) return "";
        return ts[0];
    }
};

int main() {
    char c;
    Solution sol;
    vector<string> world = { "a","banana","app","appl","ap","apply","apple" };

    cout << sol.longestWord(world);

    cin >> c;
}