// ok : use some math

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


// timeout.. 
class _Solution {
public:
    long long distributeCandies(int n, int limit) {

        long long ans = 0;

        for (int i = 0; i <= limit; ++i) {
            for (int j = 0; j <= limit; ++j) {
                int third = n - i - j;
                if (0 <= third && third <= limit) ans++;
            }
        }

        return ans;
    }
};

/* 0 <= n - i - j <= limit
   0 -n +i <= -j <= limit -n + i
   n - i >= j >= n -i -limit

   이게 also  limit >= j >= 0 이어야헤서
   각가에 대해서 n-i + 1 값을 더하면 된다. 
*/


class Solution {
public:
    int findOverlab(int max, int min, int limit) {

        if (max < 0) return 0;
        if (min > limit) return 0;

        int top = max, bott = min;

        if (top > limit) top = limit;
        if (bott < 0) bott = 0;

        return top - bott + 1;
    }


    long long distributeCandies(int n, int limit) {

        long long ans = 0;

        for (int i = 0; i <= limit; ++i) {
            ans += findOverlab(n - i, n - i - limit, limit);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;


    cout << sol.distributeCandies(1, 3);

    cin >> c;
}