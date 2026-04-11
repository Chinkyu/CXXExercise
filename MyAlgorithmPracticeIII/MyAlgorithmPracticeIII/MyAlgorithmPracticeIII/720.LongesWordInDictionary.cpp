// ok : implemt as hint 
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
#include <chrono>
#include <iterator>

using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        map<string, int> m;
        int l = words.size();
        sort(words.begin(), words.end(), [](string l, string r) {
            if (l.size() == r.size()) {
                return l < r;
            } 
            return l.size() > r.size();
            });

        for (auto& it : words) {
            m[it] = 1;
        }

        for (int i = 0; i < l; ++i) {
            int wl = words[i].size();
            for (int j = 1; j <= wl; ++j) {  // size
                if (j == wl) {
                    // reach to end == find till 
                    return words[i];
                }

                if (m.find(words[i].substr(0, j)) == m.end()) {
                    break; // not exist for sub string
                }
            }           
        }

        return "";
    }
};

#if 0
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
#endif


int main() {
    char c;
    Solution sol;

    vector<string> words = { "a","banana","app","appl","ap","apply","apple" };
    cout << sol.longestWord(words);

    cin >> c;
}
