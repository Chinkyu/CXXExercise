// Ok : Use count map and find min  and min index 
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
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int, int> m;

        for (auto& it : nums) {
            int re = it % value;

            if (re < 0) {
                re = value + re;
            }
            
            m[re]++;
        }

        // find minimum missing 
        int min = INT_MAX, min_idx = -1;
        for (int i = 0; i < value; ++i) {
            if (m[i] < min) {
                min = m[i];
                min_idx = i;
            }
        }

        return min * value + min_idx;

    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,-10,7,13,6,8 };
    cout << sol.findSmallestInteger(nums, 5);

    cin >> c;
}
