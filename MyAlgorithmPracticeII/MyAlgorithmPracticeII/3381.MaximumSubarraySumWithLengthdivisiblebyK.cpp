// 

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

// Timeout ... =- Next day 
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int l = nums.size();
        vector<long long> ac(l, 0);

        ac[0] = nums[0];
        for (int i = 1; i < l; ++i) {
            ac[i] = ac[i - 1] + nums[i];
        }

        long long tmax = LLONG_MIN;

        for (int i = -1; i + k < l; i += k) {
            tmax = max(tmax, ac[i + k]);
        }

        for (int i = 0; i < l - k; ++i) {
            for (int j = k + i; j < l; j += k) {
                tmax = max(tmax, ac[j] - ac[i]);
            }
        }

        return tmax;
    }
};


int main() {
    char c;
    Solution sol;
    //vector<int> nums = { 1, 2 };
    //vector<int> nums = { -1,-2,-3,-4,-5 };
    vector<int> nums = { -5,1,2,-3,4 };

    cout << sol.maxSubarraySum(nums, 2);

    cin >> c;
}