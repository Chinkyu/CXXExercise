// ok : logically from 1 to high 
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

    bool isPerfectSquare(int n) {
        if (n < 0) return false; // Negative numbers cannot be perfect squares
        int root = static_cast<int>(std::sqrt(n));
        return (root * root == n);
    }

    bool judgeSquareSum(int c) {
        bool ans = false;

        // till sqrt(c)
        for (int i = 0; i <= sqrt(c); ++i) {
            long long pw = pow(i, 2);
            long long b2= c - pow(i, 2);
            if (isPerfectSquare(b2)) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    char c;
    Solution sol;

    //tor<vector<int>> costs = { {10, 20}, {30, 200}, {400, 50}, {30, 20} };

    cout << sol.judgeSquareSum(999999999);

    cin >> c;
}
