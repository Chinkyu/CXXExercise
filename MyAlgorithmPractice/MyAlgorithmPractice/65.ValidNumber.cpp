// 답봤나??
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
#include <regex>
#include <memory>

using namespace std;

class _Solution {
public:

    bool isMatch(string s) {

        string mp = "(\\+|-)?[[:digit:]]+(.)?[[:digit:]]*";

        regex re(mp);
        cmatch m;

        return regex_match(s, re);
    }

    bool isNumber(string s) {
        int l = s.size();

        int eidx = -1;
        for (int i = 0; i < l; ++i) {
            if (s[i] == 'e' || s[i] == 'E') {
                eidx = i;
                break;
            }
        }

        bool ans = false;
        if (eidx != -1) {
            string ss = s.substr(0, eidx - 1);
            string ns = s.substr(eidx + 1);

            bool sm = isMatch(ss);
            bool nm = isMatch(ns);
            ans = sm && nm;

        }
        else {
            ans = isMatch(s);
        }

        return ans;
    }
};


enum STATE {
    INIT, I1, I2, I3, I4, I5, S1, S2, S3
};

bool isNum(char ch) {
    return ch >= 48 && ch <= 57;
}

class Solution {
public:
    bool isTrueState(STATE s) {
        return s == S1 || s == S2 || s == S3;
    }

    bool isNumber(string s) {
        STATE curr = INIT;

        for (int i = 0; i < s.length(); i++) {
            if (curr == INIT && (s[i] == '+' || s[i] == '-')) {
                curr = I1;
            }
            else if (curr == INIT && isNum(s[i])) {
                curr = S1;
            }
            else if (curr == INIT && s[i] == '.') {
                curr = I2;
            }
            else if (curr == I1 && isNum(s[i])) {
                curr = S1;
            }
            else if (curr == I1 && s[i] == '.') {
                curr = I2;
            }
            else if (curr == S1 && (s[i] == 'e' || s[i] == 'E')) {
                curr = I3;
            }
            else if (curr == S1 && s[i] == '.') {
                curr = S2;
            }
            else if (curr == S1 && isNum(s[i])) {
                curr = S1;
            }
            else if (curr == I2 && isNum(s[i])) {
                curr = S2;
            }
            else if (curr == I3 && isNum(s[i])) {
                curr = S3;
            }
            else if (curr == I3 && (s[i] == '+' || s[i] == '-')) {
                curr = I5;
            }
            else if (curr == S2 && (s[i] == 'e' || s[i] == 'E')) {
                curr = I4;
            }
            else if (curr == S2 && isNum(s[i])) {
                curr = S2;
            }
            else if (curr == I4 && isNum(s[i])) {
                curr = S3;
            }
            else if (curr == I4 && (s[i] == '+' || s[i] == '-')) {
                curr = I5;
            }
            else if (curr == I5 && isNum(s[i])) {
                curr = S3;
            }
            else if (curr == S3 && isNum(s[i])) {
                curr = S3;
            }
            else {
                return false;
            }
        }

        return isTrueState(curr);
    }
};

int main() {
    char c;
    Solution sol;

    //string s = "aa";
    //string p = "*";

    string s = "53.5e9e3";

    cout << sol.isNumber(s);

    cin >> c;
}