// see answer : solve wit math  n(n+1)/2
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
#include <functional>

using namespace std;


class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        int half = target / 2;
        if (n <= half) {
            long long ans = n * 1LL * (n + 1) / 2;
            return ans % 1000000007;
        }

        long long ans = half * 1LL * (half + 1) / 2 + (n - half) * 1LL * target + (n - half) * 1LL * (n - half - 1) / 2;
        return ans % 1000000007;
    }
};

// timeout
class _Solution {
public:

    bool isOK(int target, int i) {

        if (i == 1) return true;

        int half = target / 2;
        //if (target % 2 == 1) { // odd
            if (target > i && i > half) return false;
        //}
        //else {                 // even  (allow half because it is not distanict i j
        //    if (target > i && i > half) return false;
        //}

        return true;
    }

    int minimumPossibleSum(int n, int target) {

        //vector<int> num;
        long long ans = 1;
        int cnt = 1;


        for (int i = 2; cnt < n; ++i) {
            // if (isOK(target, i)) {
            if (target > i && i > target / 2) {
                continue;
            }
             
            //num.push_back(i);
            cnt++;
            ans += i;
            ans %= 1000000007;
        }

        return ans % 1000000007;
    }
};

int main() {
    char c;
    Solution sol;

    cout << sol.minimumPossibleSum(39636, 49035);


    cin >> c;
}