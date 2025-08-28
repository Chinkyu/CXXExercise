//  see answer 
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

// two pointer : 일일이 찾기... 
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        for (int i = 0; i < d.size(); i++) {
            int j = 0;
            int k = 0;
            string p = d[i];
            while (k < p.length() and j < s.length()) {
                if (s[j] == p[k]) {
                    j++;
                    k++;
                }
                else {
                    j++;
                }
            }
            if (k == p.length()) {
                if (ans.length() < p.length()) {
                    ans = p;
                }
                else if (ans.length() == p.length()) ans = min(ans, p);
            }
        }
        return ans;
    }
};

// timtoue 
class _Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        vector<string> v;

        for (auto& it : dictionary) {
            string p("[a-z]*");
            for (auto& jt : it) {
                p.push_back(jt);
                p.append("[a-z]*");
            }

            regex ptn(p);
            smatch matches;
            if (regex_match(s, ptn)) {
                v.push_back(it);
            }
        }

        if (v.size() <= 0) return "";

        // find longest and low lexicograph
        // Find the longest string using std::max_element with a custom lambda
        auto longest_it = std::max_element(v.begin(), v.end(),
            [](const std::string& a, const std::string& b) {
                if (a.size() == b.size()) {
                    return a > b;
                }
                return a.size() < b.size();
            });

        return *longest_it;
    }
};

int main() {
    char c;
    Solution sol;
    string s = "abpcplea";
    vector<string> dictionary = { "ale", "apple", "monkey", "plea" };

    cout << sol.findLongestWord(s, dictionary);

    cin >> c;
}