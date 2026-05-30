// see answer 
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

#define ll long long
class Solution {
public:
    long long countDistinct(long long n) {

        vector<ll> pow(16, 1);
        string s = to_string(n);
        ll ans = 0, i, m = s.length();
        for (i = 1; i <= 15; i++) pow[i] = pow[i - 1] * 9;
        for (i = 1; i < m; i++) ans += pow[i];
        for (i = 0; i < m; i++) {
            if (s[i] == '0') break;
            for (ll j = 1; j < s[i] - '0'; j++)
                ans += pow[m - i - 1];
        }

        return ans + (i >= s.size());
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> seats = { 1, 0, 0 , 0 };

    cout << sol.maxDistToClosest(seats);

    cin >> c;
}
