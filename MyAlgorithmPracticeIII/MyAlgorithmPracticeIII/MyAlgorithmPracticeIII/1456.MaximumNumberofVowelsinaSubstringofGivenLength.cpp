// Ok
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

    bool isVowel(char c) {

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }


    int maxVowels(string s, int k) {
        int l = s.size();

        // initial
        int c = 0;
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) {
                c++;
            }
        }

        int ans = c;
        for (int i = 0; i < l - k + 1; ++i) {
            if (isVowel(s[i])) {
                c--;
            }

            if (isVowel(s[i + k])) {
                c++;
            }

            ans = max(ans, c);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "weallloveyou";

    cout << sol.maxVowels(s, 7);

    cin >> c;
}
