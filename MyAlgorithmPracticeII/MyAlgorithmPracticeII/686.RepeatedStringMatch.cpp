// ´äÂüÁ¶ : kmp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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


int repeatedStringMatch(string A, string B) {
    for (auto i = 0, j = 0; i < A.size(); ++i) {
        for (j = 0; j < B.size() && A[(i + j) % A.size()] == B[j]; ++j);
        if (j == B.size())
            return (i + j - 1) / A.size() + 1;
    }
    return -1;
}

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int al = a.size();
        int bl = b.size();
        int ans = 0;

        if (al > bl) {
            size_t st = a.find(b);
            if (st != string::npos) return 1;

            for (int i = bl; i >= 1; --i) {
                string sl = a.substr(al - i, i);
                string sr = b.substr(0, i);
                if ( sl == sr) return 2;
            }
            return -1;
        }

        size_t st = b.find(a);
        if (st == string::npos) return -1;
         
        if (st > 0) {
            if (b.substr(0, st) != a.substr(al - st, st)) return -1;
            ans++;
        }
        int rm = (bl - st) % al;
        if ((bl - st) % al != 0) {
            if (b.substr(bl - rm, rm) != a.substr(0, rm)) return -1;
            ans++;
        }

        for (int i = st; i < bl- rm; i += al) {
            if (b.substr(i, al) != a) return -1;
        }
        ans += (bl - st) / al;

        return ans;
    }
};

int main() {
    Solution sol;
    char c;
    string a = "abcd";
    string b = "cdabcdab";

    cout << sol.repeatedStringMatch(a, b);

    cin >> c;
}
