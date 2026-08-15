// hint : even set and odd set same   -> can
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

using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {

        unordered_map<char, int> s1_odd, s1_even, s2_odd, s2_even;

        for (int i = 0; i < s1.size(); ++i) {
            if (i % 2 == 0) {
                s1_even[s1[i]]++;
            }
            else {
                s1_odd[s1[i]]++;
            }
        }

        for (int i = 0; i < s2.size(); ++i) {
            if (i % 2 == 0) {
                s2_even[s2[i]]++;
            }
            else {
                s2_odd[s2[i]]++;
            }
        }

        if ((s1_even == s2_even) && (s1_odd == s2_odd)) {
            return true;
        }

        return false;
    }
};

int main() {
    char c;
    //vector<vector<int>> n = { { -2, -2, 1, 1},{2, 2, 4, 6} };
    vector<vector<int>> n = { { 1, 1, 5, 5} };


    Solution sol(n);

    for (int i = 0; i < 5; ++i) {
        vector<int> ans = sol.pick();
        cout << ans[0] << " " << ans[1] << endl;
    }

    cin >> c;
}
