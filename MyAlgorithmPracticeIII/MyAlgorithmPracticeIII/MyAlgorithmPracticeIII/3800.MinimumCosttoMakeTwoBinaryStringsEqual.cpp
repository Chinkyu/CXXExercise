// see answer : smart solutins 
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
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        long long c[2] = { 0, 0 };
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) {
                c[s[i] - '0']++;
            }
        }
        long long c0 = c[0], c1 = c[1];
        long long res1 = (c0 + c1) * (long long)flipCost;
        long long res2 = min(c0, c1) * swapCost + abs(c0 - c1) * (long long)flipCost;
        long long res3 = min(c0, c1) * swapCost + (abs(c0 - c1) / 2) * ((long long)swapCost + crossCost) + (abs(c0 - c1) % 2) * (long long)flipCost;
        return min({ res1, res2, res3 });
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums =
        //{ 0, 1 };
    { -1, 1, 0 };

    cout << sol.centeredSubarrays(nums);

    cin >> c;
}
