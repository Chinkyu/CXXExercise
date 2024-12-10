//   ¥‰∫√¿Ω : 
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
    string decodeAtIndex(string s, int k) {
        long long len = 0;
        int n = s.size();
        int s0 = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (isalpha(c)) {
                len++;
                if (k == len)//good lucky         
                    return string(1, c);
            }
            else {
                len *= (c - '0');
            }
            if (k <= len) {
                s0 = i;
                break;
            }
        }
        //    cout<<"s0="<<s0<<"-> len="<<len<<endl;

            //The last character is a number
        for (int i = s0; i >= 0; i--) {
            char c = s[i];
            k %= len;
            if (k == 0 && isalpha(c)) return string(1, c);
            if (isdigit(c)) {
                len /= (c - '0');
            }
            else len--;
        }
        return "X";
    }
};


class __Solution {
public:
    string decodeAtIndex(string s, int k) {
        string tape;
        int repeat = 0;
        int idx = 1;
        string ans;

        if (idx == k) {
            ans.push_back(s[i])
        }

        for (int i = 0; i < s.size(); ++i) {

            if ('a' <= s[i] && s[i] <= 'z') {

            }
            else {
                repeat *= 10;
                repeat += s[i] - '0';
            }
            idx++;
        }
    }
};

int main() {
    char c;
    Solution sol;

    cout << sol.reorderedPowerOf2(16);

    cin >> c;
}