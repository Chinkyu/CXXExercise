// ok. 
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
    int numSub(string s) {
        int l = s.size();
        int ans = 0;

        int pre = 0;
        long long cnt = 0;
        for (int i = 0; i < l; ++i) {

            if (s[i] == '1') {
                cnt++;
            }

            if (pre == '1' && s[i] == '0') {
                // change 
                long long sum = (cnt * (cnt + 1)) / 2;
                sum %= 1000000007;
                ans += sum;
                ans %= 1000000007;
            }

            if (s[i] == '0') {
                cnt = 0;
            }

            pre = s[i];
        }

        if (cnt > 0) {
            long long sum = (cnt * (cnt + 1)) / 2;
            sum %= 1000000007;
            ans += sum;
            ans %= 1000000007;
        }

        return ans;
    }
};



int main() {
    char c;
    Solution sol;

    string s = "0110111";

    cout << sol.numSub(s);


    cin >> c;
}
