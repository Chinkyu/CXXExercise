// ok : use array and set and use normalize function
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
#include <random>
#include <chrono>
#include <iterator>

using namespace std;


// Timeout......   How to reduce  -> got idea.. 
//  got all map  -> remove sub string's map -> calcurate last position... 
class _Solution {
public:

    void preprocessing(string &s) {
        unordered_map<char, int> m;

        for (auto& it : s) {
            m[it]++;
        }

        string ans;
        if (m['U'] > m['D']) {
            m['U'] -= m['D'];
            m['D'] = 0;
        }
        else {
            m['D'] -= m['U'];
            m['U'] = 0;
        }

        if (m['L'] > m['R']) {
            m['L'] -= m['R'];
            m['R'] = 0;
        }
        else {
            m['R'] -= m['L'];
            m['L'] = 0;
        }

        for (auto& it : m) {
            ans.append(it.second, it.first);
        }

        s = ans;
    }

    int distinctPoints(string s, int k) {
        int l = s.size();

        if (l == k) {
            return 1;
        }

        set<string> st;
        for (int i = 0; i <= l - k; ++i) {
            string ts = s;
            ts.erase(i, k);

            // Need preprocess   LR erase,  UD erase 
            preprocessing(ts);

            sort(ts.begin(), ts.end());
            st.insert(ts);
        }

        return st.size();
    }
};

class Solution {
public:
    void normalize(vector<int> &v) {
        v[0] -= v[1];
        if (v[0] < 0) {
            v[1] = -v[0];
            v[0] = 0;
        }
        else {
            v[1] = 0;
        }

        v[2] -= v[3];
        if (v[2] < 0) {
            v[3] = -v[2];
            v[2] = 0;
        }
        else {
            v[3] = 0;
        }
    }

    // U, D, L, R 
    int distinctPoints(string s, int k) {
        int l = s.size();
        vector<int>  sv(4, 0);

        if (l == k) {
            return 1;
        }

        for (auto& it : s) {
            switch (it) {
            case 'U': sv[0]++; break;
            case 'D': sv[1]++; break;
            case 'L': sv[2]++; break;
            case 'R': sv[3]++; break;
            }
        }

        set <vector<int>> st;

        // first slide
        vector<int> lv(4, 0);
        for (int i = 0; i < k; ++i) {
            switch (s[i]) {
            case 'U': lv[0]++; break;
            case 'D': lv[1]++; break;
            case 'L': lv[2]++; break;
            case 'R': lv[3]++; break;
            }
        }

        // substract
        vector<int> tv = sv;
        for (int i = 0; i < 4; ++i) {
            tv[i] -= lv[i];
        }

        normalize(tv);
        st.insert(tv);

        for (int i = 0; i < l - k; ++i) {

            // remove first
            switch (s[i]) {
            case 'U': lv[0]--; break;
            case 'D': lv[1]--; break;
            case 'L': lv[2]--; break;
            case 'R': lv[3]--; break;
            }

            // add last
            switch (s[i + k]) {
            case 'U': lv[0]++; break;
            case 'D': lv[1]++; break;
            case 'L': lv[2]++; break;
            case 'R': lv[3]++; break;
            }

            // substract
            vector<int> tv = sv;
            for (int i = 0; i < 4; ++i) {
                tv[i] -= lv[i];
            }

            normalize(tv);
            st.insert(tv);
        }

        return st.size();
    }
};


int main() {
    char c;
    Solution sol;

    string s = "UU";
    cout << sol.distinctPoints(s, 1);

    cin >> c;
}
