// see answer : monotonic stack 
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
#include <numeric>

using namespace std;

class _Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> m;
        int l = s.size();


        int st = 0;
        int t_max = 0;
        //m[s[st]]++;
        string ans = "";

        for (int i = 0; i < l; ++i) {
            while (m[s[i]] > 0) {
                m[s[st]]--;
                st++;
            }
            m[s[i]]++;

            // maintain 
            string ts = s.substr(st, i - st + 1);
            if (ts.size() > ans.size()) {
                ans = ts;
            } else if (ts.size() == ans.size() && ts < ans ) {
                ans = ts;
            }
        }

        return ans;
    }
};

class __Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> m;
        int l = s.size();

        string ans = "";
        for (int i = 0; i < l; ++i) {
            m.clear();
            string ts = "";
            for (int j = i; j < l; ++j) {
                m[s[j]]++;
                if (m[s[j]] > 1) continue;
                ts.push_back(s[j]);
            }

            if (ts.size() > ans.size()) {
                ans = ts;
            }
            else if (ts.size() == ans.size() && ts < ans) {
                ans = ts;
            }

        }

        return ans;
    }
};


class Solution {
public:
    string smallestSubsequence(string s) {
        int freq[27] = { 0 };
        bitset<27> seen;
        string stack;

        for (auto& c : s)
            freq[c & 31]++;

        for (auto& c : s) {
            int x = c & 31;
            freq[x]--;

            if (seen.test(x))
                continue;

            while (stack.length() && stack.back() > c && freq[stack.back() & 31]) {
                seen.reset(stack.back() & 31);
                stack.pop_back();
            }

            stack.push_back(c);
            seen.set(x);
        }

        return stack;
    }
};

int main() {
    char c;

    Solution sol;

    string s = "cbacdcbc";

    cout << sol.smallestSubsequence(s);

    cin >> c;
}
