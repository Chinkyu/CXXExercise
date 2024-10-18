// 답봤네.... : 큐가지고 풀고 depth 를 큐에 가지고 있으면 됨..
// 이게 rgionalble.. 함. 
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
    static int openLock(vector<string>& deadends, const string& target) {
        bitset<10000> seen = 0;// 0000~9999
        for (string& s : deadends) {
            seen[stoi(s)] = 1;
        }
        if (seen[0]) return -1;//edge case
        queue<pair<short, short>> q;
        q.emplace(0, 0);
        seen[0] = 1;
        short z = stoi(target);
        short dec[4] = { 1, 10, 100,1000 };
        while (!q.empty()) {
            auto [turn, s] = q.front(); q.pop();
            //    cout<<turn<<":"<<s<<endl;
            if (s == z) return turn;
            short digit, t = s;
            for (short d = 0; d < 4; d++) {// 8 ways of turning
                digit = t % 10, t /= 10;
                for (short i : {-1, 1}) {
                    short dnext = (digit + i + 10) % 10;
                    short x = s + (dnext - digit) * dec[d];
                    if (!seen[x]) {
                        q.emplace(turn + 1, x);
                        seen[x] = 1;
                    }
                }
            }
        }
        return -1;
    }
};


class _Solution {
public:
    string up(string s, int i) {
        string o = s;
        o[i]++;
        if (o[i] == ':') o[i] = '0';
        return o;
    }

    string dn(string s, int i) {
        string o = s;
        o[i]--;
        if (o[i] == '/') o[i] = '9';
        return o;
    }

    unordered_map<string, int> m;
    int ans = INT_MAX;
    void recursive(string s, int depth, string &target) {

        if (depth > ans) return; 

        if (s == target) {
            ans = min(ans, depth);
            return;
        }

        for (int i = 0; i < 4; ++i) {
            string us = up(s, i);
            if (m.find(us) == m.end()) {
                m[us] = 1;
                recursive(us, depth + 1, target);

            }

            string ds = dn(s, i);
            if (m.find(ds) == m.end()) {
                m[ds] = 1;
                recursive(ds, depth + 1, target);
            }

        }
    }

    int openLock(vector<string>& deadends, string target) {
        m.clear();
        ans = INT_MAX;

        // deadend to visited
        for (auto& it : deadends) m[it] = 1;
        recursive("0000", 0, target);

        if (ans == INT_MAX) return -1;
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";


    cout << sol.openLock(deadends, target);

    cin >> c;
}