//  see answer
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
#include <bit>

using namespace std;


class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26);
        for (char ch : s) {
            ++cnt[ch - 'a'];
        }
        for (int round = 0; round < t; ++round) {
            vector<int> nxt(26);
            nxt[0] = cnt[25];
            nxt[1] = (cnt[25] + cnt[0]) % mod;
            for (int i = 2; i < 26; ++i) {
                nxt[i] = cnt[i - 1];
            }
            cnt = move(nxt);
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + cnt[i]) % mod;
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};

// time out 
class _Solution {
public:
    int afterNum(char c, int t) {
        multiset<int> s;
        s.insert('z' - c + 1);

        while (t > 0) {
            multiset<int>  ts;
            int m = *s.begin();
            if (m > t) {
                return s.size();
            }
            for (auto& it : s) {
                int n = it - m;
                if (n == 0) {
                    ts.insert('z' - 'a' + 1);
                    ts.insert('z' - 'b' + 1);
                }
                else {
                    ts.insert(n);
                }
            }
            t -= m;
            s = ts;
        }

        return s.size();
    }

    int lengthAfterTransformations(string s, int t) {
        unordered_map<char, int> m;

        for (auto& it : s) {
            m[it]++;
        }

        int ans = 0;
        for (auto& it : m) {
            ans += afterNum(it.first, t) * it.second;
        }

        return ans;
    }
};


int main() {
    char c;
    Solution sol;

    string s = "jqktcurgdvlibczdsvnsg";
    //"abcyy";

    cout << sol.lengthAfterTransformations(s, 7517);

    cin >> c;
}

