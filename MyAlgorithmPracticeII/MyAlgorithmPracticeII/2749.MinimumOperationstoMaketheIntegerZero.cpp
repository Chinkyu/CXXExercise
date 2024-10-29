// ¥‰∫√¿Ω... bit manifulation   
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
    int makeTheIntegerZero(long long max_opt, long long num2) {
        int n = 0;

        // for the nth operation, check in ascending order starting from 0
        while (max_opt >= 0 && n <= 61) {
            int min_opt = __builtin_popcountll(max_opt);

            // if n within range
            if (n >= min_opt && n <= max_opt) {
                return n;
            }
            n++;
            max_opt -= num2;
        }
        return -1;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> cost = { 1,5,2,2,3,3,1 };

    cout << sol.minIncrements(7, cost);

    cin >> c;
}