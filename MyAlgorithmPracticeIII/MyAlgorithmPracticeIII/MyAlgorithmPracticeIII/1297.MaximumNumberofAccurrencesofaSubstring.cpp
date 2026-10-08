// Ok : but slow ...  did misunderstanding  max char
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

class _Solution {
public:

    int getMaxCount(vector<int>& v) { 
        int tmax = 0;
        for (int i = 0; i < 26; ++i) {
            tmax = max(v[i], tmax);
        }
        return tmax;
    }

    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int l = s.size(); 
        vector<int> v(26, 0);
        unordered_map<string, int> m;

        int ans = 0;
        for (int i = minSize; i <= maxSize; ++i) {
            std::fill(v.begin(), v.end(), 0);
            for (int j = 0; j < i; ++j) {
                v[s[j] - 'a']++;
            }

            // first 
            if (getMaxCount(v) <= maxLetters) {
                ans++;
                m[s.substr(0, i)]++;
            }

            for (int j = i; j < l; ++j) {
                v[s[j - i] - 'a']--;
                v[s[j] - 'a']++;

                if (getMaxCount(v) <= maxLetters) {
                    ans++;
                    m[s.substr(j - i, i)]++;
                }
            }

        }

        ans = 0;
        for (auto& it : m) {
            ans = max(ans, it.second);
        }

        return ans;
    }
};

class Solution {
public:

    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int l = s.size();
        unordered_map<char, int> v;
        unordered_map<string, int> m;

        int ans = 0;
        for (int i = minSize; i <= maxSize; ++i) {
            v.clear();
            for (int j = 0; j < i; ++j) {
                v[s[j]]++;
            }

            // first 
            if (v.size() <= maxLetters) {
                ans++;
                m[s.substr(0, i)]++;
            }

            for (int j = i; j < l; ++j) {
                v[s[j - i]]--;
                if (v[s[j - i]] <= 0) {
                    v.erase(s[j - i]);
                }
                v[s[j]]++;

                if (v.size() <= maxLetters) {
                    ans++;
                    m[s.substr(j - i + 1, i)]++;
                }
            }

        }

        ans = 0;
        for (auto& it : m) {
            ans = max(ans, it.second);
        }

        return ans;
    }
};



int main() {
    char c;
    Solution sol;

    string s = "aabcabcab"; // "aaaa"; // "aababcaab";

    cout << sol.maxFreq(s, 2, 2, 3);


    cin >> c;
}
