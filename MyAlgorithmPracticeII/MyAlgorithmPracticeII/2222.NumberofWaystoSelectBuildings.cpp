// see anser - dp
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
    long long numberOfWays(string s) {
        long long a = 0, b = 0, ans = 0;        // a and b are the number of occurances of '1' and '0' after the current building respectively.
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1')
                a++;
            else
                b++;
        }
        long long c = 0, d = 0;              // c and d are the number of occurances of '1' and '0' before the current building respectively.
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {               // Counting the sequences of "010"
                ans += (d * b);
                a--;
                c++;
            }
            else {                        // Counting the sequences of "101"
                ans += (a * c);
                b--;
                d++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    // timeout
    long long _numberOfWays(string s) {
        int l = s.size();
        vector<int> v(l, 0), lz(l, 0), lo(l, 0);      // left zero, left one

        int zcount = 0, ocount = 0;
        for (int i = l - 1; i >= 0; --i) {
            if (s[i] == '0') zcount++;
            else ocount++;
            lz[i] = zcount;
            lo[i] = ocount;
        }

        long long ans = 0;
        // 010
        for (int i = 0; i < l - 2; ++i) {
            if (s[i] == '1') continue;
            for (int j = i + 1; j < l - 1; ++j) {
                if (s[j] == '0') continue;
                ans += lz[j];
            }
        }

        // 101
        for (int i = 0; i < l - 2; ++i) {
            if (s[i] == '0') continue;
            for (int j = i + 1; j < l - 1; ++j) {
                if (s[j] == '1') continue;
                ans += lo[j];
            }
        }

        return ans;
    }

    long long numberOfWays(string s) {
        int l = s.size();
        vector<int> v(l, 0), lz(l, 0), lo(l, 0);      // left zero, left one

        int zcount = 0, ocount = 0;
        for (int i = l - 1; i >= 0; --i) {
            if (s[i] == '0') zcount++;
            else ocount++;
            lz[i] = zcount;
            lo[i] = ocount;
        }

        long long ans = 0;
        // 010
        for (int i = 0; i < l - 2; ++i) {
            if (s[i] == '0') {
                for (int j = i + 1; j < l - 1; ++j) {
                    if (s[j] == '0') continue;
                    ans += lz[j];
                }
            }
            else {
                for (int j = i + 1; j < l - 1; ++j) {
                    if (s[j] == '1') continue;
                    ans += lo[j];
                }
            }
        }

        // 101
        for (int i = 0; i < l - 2; ++i) {
            if (s[i] == '0') continue;

        }

        return ans;
    }

};

int main() {
    char c;
    Solution sol;
    string s = "001101";

    cout << sol.numberOfWays(s);

    std::cin >> c;
}