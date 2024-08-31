// 답봤음 : 문제 이해 안감... - skip
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
    string smallestGoodBase(string n) {
        typedef unsigned long long ll;
        ll num = stol(n);
        for (ll p = log(num + 1) / log(2); p >= 2; --p) {
            ll lk = 2, rk = pow(num, 1.0 / (p - 1)) + 1;
            while (lk <= rk) {
                ll mk = lk + (rk - lk) / 2, sum = 0;
                for (ll i = 0, f = 1; i < p; ++i, f *= mk)
                    sum += f;
                if (sum < num) lk = mk + 1;
                else if (sum > num) rk = mk - 1;
                else return to_string(mk);
            }
        }
        return to_string(num - 1);
    }
};

int main() {
    Solution sol;
    char c;

    //vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    vector<int> nums = { 1,4, 2, 3 };

    vector<double> ans = sol.medianSlidingWindow(nums, 4);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
