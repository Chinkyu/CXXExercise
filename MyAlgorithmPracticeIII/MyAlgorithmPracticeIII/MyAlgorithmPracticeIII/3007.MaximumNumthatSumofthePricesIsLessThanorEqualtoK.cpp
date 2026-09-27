// see answer : bsearch 
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
    // utility function to calculate the number of bits in a number
    int countBits(long long n) {
        int count = 0;
        while (n) {
            count++;
            n = n >> 1;
        }
        return count;
    }
    // utility function to quickly get power of 2 using bit manipulation
    long long powerOf2(int i) {
        return 1LL << i;
    }
    long long calc(long long n, int x) {
        // get the leftmost bit
        int i = countBits(n);
        long long price = 0;

        // increment n to account 0th row in the count of groups
        n++;
        while (i) {
            // if current column is valid, calculate the number of 1s in the column
            if (i % x == 0)
                price += (n / powerOf2(i)) * (powerOf2(i - 1)) + max(0LL, (n % powerOf2(i)) - powerOf2(i - 1));

            // move to the next column           
            i--;
        }

        return price;
    }
    long long findMaximumNumber(long long k, int x) {
        long long low = 1;
        long long high = 1e15;

        // binary search
        while (low <= high) {
            long long mid = (high - low) / 2 + low;
            long long res = calc(mid, x);
            if (res <= k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};

// timeout 
class _Solution {
public:

    int countOne(long long n, int x) {
        int ans = 0;
        while (n > 0) {
            n = n >> (x - 1);
            if ((n & 01) == 01) {
                ans++;
            }
            n = n >> 1;
        }
        return ans;
    }


    long long findMaximumNumber(long long k, int x) {

        long long aprice = 0;

        long long i = 0;
        do {
            i++;
            aprice += countOne(i, x);
        } while (aprice <= k);

        return i - 1;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 4, -2, -3, 4, 1 };
    cout << sol.findMaximumNumber(9, 1);

    cin >> c;
}
