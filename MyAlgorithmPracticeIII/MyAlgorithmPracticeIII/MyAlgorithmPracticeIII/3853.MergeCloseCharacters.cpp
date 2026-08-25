// ok... use map to indicate latest index of this char
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
#include <numeric>

using namespace std;

class _Solution {
public:
    string mergeCharacters(string s, int k) {

        int l = s.size();

        for (int i = 0; i < s.size(); ++i) {
            for (int j = i + 1; j < s.size() && j <= i + k; ++j) {
                if (s[i] == s[j]) {
                    s.erase(s.begin() + j);
                    j--;
                }
            }
        }


        return s;
    }
};

class Solution {
public:
    string mergeCharacters(string s, int k) {

        unordered_map<char, int> m;

        for (int i = 0; i < s.size(); ++i) {
            if (m.find(s[i]) != m.end() && i <= m[s[i]] + k) {
                s.erase(s.begin() + i);
                i--;
                continue;
            }
            
            m[s[i]] = i;
        }

        return s;
    }
};




int main() {
    char c;
    Solution sol;

    string s = "aabca";

    cout << sol.mergeCharacters(s, 2);
    cin >> c;
}
