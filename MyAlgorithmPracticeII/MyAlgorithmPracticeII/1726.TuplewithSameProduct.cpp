// see answer
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <cmath>
#include <regex>
#include <memory>

using namespace std;

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                ans += 8 * mp[product];
                mp[product]++;
            }
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    string s = "ksztajnymer";
    vector<vector<int>> shifts =
    { {4, 9, 1}, {2, 5, 1}, {7, 9, 0}, {6, 10, 0}, {1, 7, 1}, {0, 7, 1}, {0, 3, 0}, {3, 3, 1}, {7, 9, 0}, {7, 7, 0}, {6, 7, 0}, {7, 9, 0}, {3, 9, 0}, {10, 10, 1}, {8, 9, 0}, {6, 9, 1}, {1, 2, 1}, {3, 9, 0}, {8, 10, 1}, {4, 7, 1}, {9, 10, 1}, {8, 9, 0}, {5, 8, 0}, {8, 9, 1}, {0, 7, 1}, {2, 2, 1}, {8, 8, 1}, {3, 7, 0}, {1, 10, 1}, {9, 9, 1}, {4, 9, 0}, {5, 6, 1}, {7, 8, 1}, {8, 9, 0}, {7, 7, 1}, {9, 9, 1} };


    cout << sol.shiftingLetters(s, shifts);

    std::cin >> c;
}