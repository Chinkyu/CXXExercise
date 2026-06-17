// tgricky with flag..... etc. 
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
    bool checkPossibility(vector<int>& nums) {
        
        int l = nums.size();

        // count decreasing gap 
        int dec = 0;
        int tmax = INT_MIN; 
        bool after_down = false;
        for (int i = 0; i < l - 1; ++i) {
            if (nums[i] - nums[i + 1] > 0) {
                dec++;
                if (dec > 1) return false;

                if (tmax <= nums[i + 1]) {  // modify num[i]
                    tmax = max(nums[i+ 1], tmax);
                }
                else {   // modify num[i + 1]
                    tmax = max(nums[i], tmax);
                }
                after_down = true;
                continue;
            }

            if (nums[i] < tmax && after_down != true) return false;
            after_down = false;
            tmax = max(nums[i], tmax);
        }

        // Need to check last one
        if (nums[l - 1] < tmax && after_down != true) return false;

        return true;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 5, 7, 1, 8 };

    cout << sol.checkPossibility(nums);

    cin >> c;
}
