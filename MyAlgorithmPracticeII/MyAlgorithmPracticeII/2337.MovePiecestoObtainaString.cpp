//  답봤음 : 문제 이해 잘 못 했음 
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
    bool canChange(string st, string tar) {
        int n = tar.length();
        int i = 0, j = 0;
        while (i <= n && j <= n) {

            while (i < n && tar[i] == '_') i++;
            while (j < n && st[j] == '_') j++;

            if (i == n || j == n) {
                return i == n && j == n;
            }

            if (tar[i] != st[j]) return false;

            if (tar[i] == 'L') {
                if (j < i) return false;
            }
            else {
                if (i < j) return false;
            }

            i++;
            j++;
        }
        return true;
    }
};

// 문제 이해 잘 못 했음. 
class _Solution {
public:
    string normalize(string s) {

        string ans = "";

        for (int i = 0; i < s.size(); ++i) {
            if (ans.size() <= 0) {
                ans.push_back(s[i]);
                continue;
            }

            if (s[i] == '_') {
                if (ans.back() == 'R'){
                    continue;
                }
            }

            if (s[i] == 'L') {
                while (ans.size() > 0 && ans.back() == '_') {
                    ans.pop_back();
                }
            }

            ans.push_back(s[i]);
        }

        return ans;
    }

    bool canChange(string start, string target) {
        string sm, tm;

        sm = normalize(start);
        cout << sm << endl;
        tm = normalize(target);
        cout << tm << endl;

        if (sm == tm) return true;

        return false;
    }
};

int main() {
    char c;
    Solution sol;
    //string s = "__R_L";
    //string t = "L_R__";
    string s = "_LL__R__R_";
    string t = "L___L___RR";


    cout << sol.canChange(s, t);

    cin >> c;
}