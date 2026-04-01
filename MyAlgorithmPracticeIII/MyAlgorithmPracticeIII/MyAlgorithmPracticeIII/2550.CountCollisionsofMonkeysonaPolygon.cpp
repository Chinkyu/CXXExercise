// see answer :  fast pow  checked from  google. 
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

    long long fastPower(long long base, long long exp) {
        long long res = 1;
        long long b = base;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = res * b % 1000000007; // If exponent is odd, multiply result by current base
            }
            b = b * b % 1000000007; // Square the base
            exp /= 2; // Halve the exponent
        }
        return res;
    }

    int monkeyMove(int n) {

        int ans = fastPower(2, n) % 1000000007;

        ans -= 2;
        if (ans < 0) ans = 1000000007 + ans;
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> plants = { 2, 2, 3, 3 };

    cout << sol.minimumRefill(plants, 5, 3);

    cin >> c;
}
