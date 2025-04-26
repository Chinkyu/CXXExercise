//  see answer
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
#include <set>
#include <list>
#include <regex>
#include <memory>
#include <functional>

using namespace std;

typedef long long ll;
class Solution {
public:
    const ll mod = (ll)(1e9 + 7);
    int maximumXorProduct(long long a, long long b, int n) {
        for (ll i = n - 1; i >= 0; i--) {
            ll bit = (ll)(1) << i;
            if ((bit & a) == (bit & b)) {
                a = a | bit;
                b = b | bit;
            }
            else {
                if (a > b) swap(a, b);
                a = a | bit;
                b = b & (~bit);
            }
        }
        return ((a % mod) * (b % mod)) % mod;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<vector<int>> grid = { {1, 3, 1}, {1, 5, 1}, {4, 2, 1} };
    vector<vector<int>> grid = { {0} };

    cout << sol.minPathSum(grid);

    cin >> c;
}