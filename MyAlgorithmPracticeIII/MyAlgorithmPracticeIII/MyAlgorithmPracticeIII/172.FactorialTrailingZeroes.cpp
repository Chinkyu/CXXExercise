// see answer :  need count 0  2x5,  25x4...
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

class _Solution {
public:
    int trailingZeroes(int n) {
        long long la = 1;

        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            la *= i;
            // »ý±â´Â Á·Á· »©¸Ô¾îµµ µÊ.
            while (la % 10 == 0) {
                ans++;
                la /= 10;
            }
        }

        //int ans = 0;
        while (la % 10 == 0) {
            ans++;
            la /= 10;
        }

        return ans;
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        return (n / 5) + (n / (5 * 5)) + (n / (5 * 5 * 5)) + (n / (5 * 5 * 5 * 5)) + (n / (5 * 5 * 5 * 5 * 5));
    }
};


int main() {
    char c;
    Solution sol;

    //vector<int> nums = { 0,3,7,2,5,8,4,6,0,1 };

    cout << sol.trailingZeroes(5);

    cin >> c;
}
