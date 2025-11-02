// easy
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
    int minIncrementForUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int l = 0; 
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i, ++l) {
            if (nums[i] > l) {
                l = nums[i];
                continue;
            }

            ans += l - nums[i];
        }

        return ans;
    }
};

    int main() {
        Solution sol;
        char c;
        vector<int> nums = { 3,2,1,2,1,7 };

        cout  << sol.minIncrementForUnique(nums);

        cin >> c;
    }
