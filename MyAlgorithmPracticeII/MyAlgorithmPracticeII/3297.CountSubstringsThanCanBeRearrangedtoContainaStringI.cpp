//  sliding window
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

long long validSubstringCount(string s1, string s2) {
    vector<int> v(26, 0);
    for (char c : s2) {
        v[c - 'a']++;
    }

    vector<int> cnt(26, 0);
    int start = 0, k = s2.length();
    long long c = 0;

    for (int i = 0; i < s1.length(); i++) {
        char curr = s1[i];

        if (v[curr - 'a'] > 0) {
            if (cnt[curr - 'a'] < v[curr - 'a']) {
                k--;
            }
        }

        cnt[curr - 'a']++;

        while (k == 0) {
            c += s1.length() - i;

            char pre = s1[start];
            cnt[pre - 'a']--;

            if (v[pre - 'a'] > 0 and cnt[pre - 'a'] < v[pre - 'a']) {
                k++;
            }

            start++;
        }
    }

    return c;
}

int main() {
    char c;
    Solution sol;
    string s = "1001101";

    cout << sol.maxOperations(s);

    cin >> c;
}