// see answer - dp.. 
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

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(size(nums), INT_MIN);
        multiset<int> s({ dp[0] = nums[0] });         // set dp[0] = nums[0] and insert it into set
        for (int i = 1; i < size(nums); i++) {
            if (i > k) s.erase(s.find(dp[i - k - 1]));  // erase elements from which we cant jump to current index
            s.insert(dp[i] = *rbegin(s) + nums[i]);    // choose element with max score and jump from that to the current index
        }
        return dp.back();
    }
};


// non dp.. memoization  timeout 
class _Solution {
public:

    vector<int> memo;

    int traverse(vector<int>& nums, int k, int idx) {
        int l = nums.size();

        if (idx >= l) return 0;

        int t_max = INT_MIN;
        for (int i = idx + 1; i < l && i <= idx + k; ++i) {
            if (memo[idx] != INT_MIN) {
                t_max = max(t_max, memo[i]);
            }
            else {
                
                t_max = max(t_max, traverse(nums, k, i));
            }
        }

        
        if (t_max == INT_MIN) {
            memo[idx] = nums[idx];
            return nums[idx];
        }
        else {
            memo[idx] = t_max + nums[idx];
            return t_max + nums[idx];
        }
    }


    int maxResult(vector<int>& nums, int k) {
        int l = nums.size();
        memo = vector<int>(l, INT_MIN);
        // do all 
        return traverse(nums, k, 0);
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> nums = { 1,-1,-2,4,-7,3 };

    cout << sol.maxResult(nums, 2);

    std::cin >> c;
}