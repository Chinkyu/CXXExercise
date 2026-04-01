// ok
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

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.size();

        if (l == 1) return 1;

        int ans = 0;
        for (int i = 0; i < l; ++i) {
            unordered_map<char, int> m;
            for (int j = i; j < l; ++j) {
                m[s[j]]++;
                if (m[s[j]] > 1) {
                    ans = max(ans, j - i);
                    break;
                } 

                if (j == l - 1) {
                    ans = max(ans, j - i + 1);
                }
            }

        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "au";
    //"abcabcbb";

    cout << sol.lengthOfLongestSubstring(s);

    cin >> c;
}
