// ¥‰∫√¿Ω :  bsearch
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

using namespace std;

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int i = 0, j = removable.size(), ans = 0;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            string s1 = s;
            for (int i = 0; i < mid; i++) {
                s1[removable[i]] = 'A';
            }
            int l = p.size(), k = 0;
            for (int i = 0; i < s1.size() && k < l; i++) {
                if (s1[i] == p[k]) { k++; }
            }
            cout << mid << " " << l << " " << k << endl;
            if (l == k) {
                ans = mid;
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }
        return ans;
    }
};

// timeout with regexp
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {

        string mp = "[a-z0]*";
        for (int i = 0; i < p.size(); ++i) {
            mp.push_back(p[i]);
            mp.append("[a-z0]*");
        }

        regex re(mp); //  "[a-z]*a[a-z]*b[a-z]*");
        cmatch m;

        int i = 0;
        for (i = 0; i < removable.size(); ++i) {
            //s.erase(removable[i], 1);
            s[removable[i]] = '0';
            if (!std::regex_match(s, re)) {
                return i;
            }

        }
        return i;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "qobftgcueho";
    string p = "obue";
    vector<int> removable = { 5,3,0,6,4,9,10,7,2,8 };
    cout << sol.maximumRemovals(s, p, removable);
    cin >> c;
}