// ok : exception   total size is shorter than k
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
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> m;

        for (auto& it : words) {
            if (it.size() >= k) {
                m[it.substr(0, k)]++;
            }
        }

        int ans = 0;
        for (auto& it : m) {
            if (it.second >= 2) {
                ans++;
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
