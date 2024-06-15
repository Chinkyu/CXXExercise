// ¥‰∫√¿Ω : ....   manually checking 
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

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, asterick = -1, match;
        while (i < m) {
            if (j < n && p[j] == '*') {
                match = i;
                asterick = j++;
            }
            else if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            }
            else if (asterick >= 0) {
                i = ++match;
                j = asterick + 1;
            }
            else return false;
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};

// timeout 
class _Solution {
public:
	bool isMatch(string s, string p) {
        string mp;
        int l = p.size();

        for (int i = 0; i < l; ++i) {
            if (i >= 1 && p[i] == '*' && p[i - 1] == '*') continue;

            if (p[i] == '?') {
                mp.append("[a-z]");
            }
            else if (p[i] == '*') {
                mp.append("[a-z]*");

            }
            else mp.push_back(p[i]);

        }

        //regex re(mp);
        regex re("[a-z]*b[a-z]*aba[a-z]*babaa[a-z]*bbaba[a-z]*a[a-z]*aaba[a-z]*b[a-z]*aa[a-z]*a[a-z]*b[a-z]*ba[a-z]*");
        cmatch m;

        bool ans =  regex_match(s, re);
        return ans;
	}
};

int main() {
	char c;
	Solution sol;

    //string s = "aa";
    //string p = "*";

    string s = "aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba";
    string p = "*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*";

    cout << sol.isMatch(s, p);

	cin >> c;
}