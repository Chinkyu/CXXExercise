// 답봤음...... :
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
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        std::vector<int> map(128, 0);
        int count = t.length();
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
        /// UPVOTE !
        for (char c : t) {
            map[c]++;
        }

        while (end < s.length()) {
            if (map[s[end++]]-- > 0) {
                count--;
            }

            while (count == 0) {
                if (end - start < minLen) {
                    startIndex = start;
                    minLen = end - start;
                }

                if (map[s[start++]]++ == 0) {
                    count++;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};

// Lost in exception handling 
class _Solution {
public:

    bool isContain(unordered_map<char, int>& tm, unordered_map<char, int>& sm) {
        for (auto& it : tm) {
            if (sm[it.first] < it.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int l = s.size();
        int lt = t.size();

        if (l < lt) return "";
        if (l == lt) {
            if (s == t) return s;
            else return "";
        }


        unordered_map<char, int> tm;

        for (auto& it : t) tm[it]++;

        // find first start 
        int st = 0;
        for (int i = 0; i < l; ++i) {
            if (tm.find(s[i]) != tm.end()) {
                st = i;
                break;
            }
        }

        // find first end
        unordered_map<char, int> sm;
        int ed = 0;
        for (int i = st; i < l; ++i) {
            sm[s[i]]++;

            if (isContain(tm, sm)) {
                ed = i;
                break;
            }
        }

        if (st == ed) {
            if (lt == 1 && s[st] != t[0]) {
                return "";
            }
            else {
                // nothing 
            }
        }

        int min_size = ed - st;
        string ans = s.substr(st, min_size + 1);

        while(ed < l - 1) {
            // find next match 
            char sc = s[st];

            // find next start
            int p_st = st;
            for (int i = st + 1; i < l; ++i) {
                if (tm.find(s[i]) != tm.end()) {
                    st = i;
                    break;
                }
            }
            if (st == l - 1) break;

            // find next end
            for (int i = ed + 1; i < l; ++i) {
                if (s[i] == sc) {
                    ed = i;
                    break;
                }
            }

            if (min_size > ed - st) {
                min_size = ed - st;
                ans = s.substr(st, min_size + 1);
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    //string s = "ADOBECODEBANC", t = "ABC";
    string s = "abc", t = "ab";

    cout << sol.minWindow(s, t);

    cin >> c;
}