// tricky : debugging 
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
    void hangprocess(string equation, int st, int ed, int sign, int& lv, int& rv) {
        if (equation[ed] == 'x') {
            if (ed - st == 1 && (equation[st] == '+' || equation[st] == '-')) {
                if (equation[st] == '+') {
                    lv += sign;
                }
                else {
                    lv += sign * -1;
                }
            }
            else if (ed - st >= 1) {
                string s(equation.substr(st, ed - st));
                lv += stoi(s) * sign;
            }
            else {
                lv += sign;
            }
        }
        else {
            if (ed - st >= 0) {
                string s(equation.substr(st, ed - st + 1));
                rv += stoi(s) * sign * -1;
            }
        }
    }


    string solveEquation(string equation) {

        int sign = 1;

        int lv = 0, rv = 0;

        int tst = 0, ted = 0;
        int i = 0;
        if (equation[0] == '+' || equation[0] == '-') i++;
        for (; i < equation.size(); ++i) {

            switch (equation[i]) {
            case '=':
                hangprocess(equation, tst, i - 1, sign, lv, rv);
                sign = -1;
                tst = i + 1;
                break;
            case '+':
                hangprocess(equation, tst, i - 1, sign, lv, rv);
                tst = i;
                break;
            case '-':
                hangprocess(equation, tst, i - 1, sign, lv, rv);
                tst = i;
                break;
            default:
                break;
            }
        }

        if (tst < equation.size()) {
            hangprocess(equation, tst, equation.size() - 1, sign, lv, rv);
        }

        if (lv == 0 && rv == 0) return "Infinite solutions";
        if (lv == 0 && rv != 0) return "No solution";
        int ans = rv / lv;
        return "x="+to_string(ans);

    }
};

int main() {
    char c;
    Solution sol;
    string equation = "-x=-1"; // "x+5-3+x=6+x-2"; //"2x=x"; 

    cout << sol.solveEquation(equation);

    cin >> c;
}