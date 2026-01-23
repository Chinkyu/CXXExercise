// Ok. 
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
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long ans = 0;
        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
            ans += nums[--j];
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 2,1,3,2,1,3 };

    cout << sol.maximumMedianSum(nums);

    cin >> c;
}
