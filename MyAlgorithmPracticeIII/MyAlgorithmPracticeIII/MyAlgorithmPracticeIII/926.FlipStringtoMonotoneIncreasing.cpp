// Ok : check left1  and check right zero : need to check l + 1

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
    int minFlipsMonoIncr(string s) {
        int l = s.size();

        // check number of one till i
        // check number of zero after i 


        vector<int> l1(l + 1, 0), r0(l + 1, 0);

        // number of one till i
        int cnt = 0;
        for (int i = 0; i < l; ++i) {
            if (s[i] == '1') cnt++;
            l1[i] = cnt;
        }
        l1.insert(l1.begin(), 0);  // make start from 0


        // number of zero after i
        cnt = 0;
        for (int i = l - 1; i >= 0; --i) {
            r0[i] = cnt;
            if (s[i] == '0') cnt++;
        }
        r0.insert(r0.begin(), cnt);  // make start from cnt

        int ans = INT_MAX;
        for (int i = 0; i < l + 1; ++i) {
            ans = min(ans, l1[i] + r0[i]);
        }

        return ans;

    }
};

int main() {
    char c;
    Solution sol;

    string s = "00011000";
    cout << sol.minFlipsMonoIncr( s);


    cin >> c;
}
