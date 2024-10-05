// easy : 
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
    int minDifference(vector<int>& nums) {
        int l = nums.size();

        if (l <= 3) return 0;

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;

        ans = min(ans, nums[l - 1] - nums[3]);
        ans = min(ans, nums[l - 1 - 1] - nums[2]);
        ans = min(ans, nums[l - 1 - 2] - nums[1]);
        ans = min(ans, nums[l - 1 - 3] - nums[0]);

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> nums = { 5,3,2,4 };
    cout << sol.minDifference(nums);

    cin >> c;
}