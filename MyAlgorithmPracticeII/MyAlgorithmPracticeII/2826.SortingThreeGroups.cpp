//  ¥‰∫√¿Ω  : Need dp to remove timeout (Memoization)
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
    int solve(vector<int>& nums, int i, int last, vector<vector<int>>& dp) {
        if (i < 0) return 0;
        if (last < 1) return 1000;
        if (dp[i][last] != -1) return dp[i][last];
        int res = INT_MAX;
        if (last == nums[i]) res = solve(nums, i - 1, last, dp);
        else {
            if (nums[i] < last) res = min(res, solve(nums, i - 1, nums[i], dp));
            res = min(res, 1 + solve(nums, i - 1, last, dp));
            res = min(res, 1 + solve(nums, i - 1, last - 1, dp));
        }
        return dp[i][last] = res;
    }
    int minimumOperations(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(4, -1));
        return solve(nums, nums.size() - 1, 3, dp);
    }
};

// timeout... 
class Solution {
public:
    int max_cnt = 0;
    int traverse(vector<int>& nums, int pre_val, int i, int cnt) {

        if (i == nums.size()) {
            max_cnt = max(max_cnt, cnt);
            return cnt;
        }

        // user it 
        if (pre_val <= nums[i]) {
            traverse(nums, nums[i], i + 1, cnt + 1);
        }

        // not use it (remove)
        traverse(nums, pre_val, i + 1, cnt);
        return 0;
    }

    int minimumOperations(vector<int>& nums) {
        max_cnt = 0;
        traverse(nums, 0, 0, 0);

        return nums.size() - max_cnt;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<int> nums = { 2, 1, 3, 2, 1 };
    vector<int> nums = { 3, 1, 2};


    cout << sol.minimumOperations(nums);

    cin >> c;
}