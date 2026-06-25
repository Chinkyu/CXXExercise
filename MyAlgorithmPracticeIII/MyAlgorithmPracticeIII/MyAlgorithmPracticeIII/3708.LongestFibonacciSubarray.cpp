// ok..  count from 2  if matching 
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
    int longestSubarray(vector<int>& nums) {
        int l = nums.size();

        if (l <= 2) {
            return l;
        }


        int ans = 0;
        int t_sum = 2;
        for (int i = 2; i < l; ++i) {
            if (nums[i] == nums[i - 1] + nums[i - 2]) {
                t_sum++;
            }
            else {
                ans = max(ans, t_sum);
                t_sum = 2;
            }
        }

        ans = max(ans, t_sum);
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums{ 5,2,7,9,16 };
    cout << sol.longestSubarray(nums);

    cin >> c;
}
