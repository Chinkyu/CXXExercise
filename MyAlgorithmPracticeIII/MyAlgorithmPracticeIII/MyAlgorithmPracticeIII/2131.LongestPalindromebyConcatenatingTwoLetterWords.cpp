// ok : tricky debugging with same double char
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
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;

        for (auto& it : words) {
            m[it]++;
        }

        int ans = 0;
        int sym = 0;
        for (auto& it : m) {

            if (it.first[0] == it.first[1]) {
                if (it.second > 1) {
                    ans += (it.second / 2) * 2;
                    sym = ((it.second % 2) == 1) ? 1 : sym;
                }
                else if(it.second == 1) {
                    sym = 1;
                }
                continue;
            }

            if (it.second > 0) {
                string rev = { it.first[1], it.first[0] };
                if (m.find(rev) != m.end()) {

                    ans += min(it.second, m[rev]) * 2;
                    it.second = 0;
                    m[rev] = 0;
                }
            }
        }

        ans += sym;
        return ans * 2;
    }
};

int main() {
    char c;
    Solution sol;

    //vector<string> words = {"lc", "cl", "gg"};
    vector<string> words = { "dd","aa","bb","dd","aa","dd","bb","dd","aa","cc","bb","cc","dd","cc" };

    cout << sol.longestPalindrome(words);

    cin >> c;
}
