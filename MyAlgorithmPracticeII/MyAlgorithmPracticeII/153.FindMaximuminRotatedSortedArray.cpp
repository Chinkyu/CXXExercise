// ok :  binary search
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

    int findMin(vector<int>& nums) {
        int l = nums.size();

        int st = 0, ed = l - 1;

        // check sorted

        do {
            bool l = false, r = false;
            int md = (st + ed) / 2;
            if (nums[st] <= nums[md]) l = true;
            if (nums[md] <= nums[ed]) r = true;

            if (l == true && r == true) return nums[st];

            if (l == true) st = md; else ed = md;

            if (st + 1 == ed || st == ed) {
                return min(nums[st], nums[ed]);
            }

        } while (st < ed);


        return -1;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> nums = { 4,5,6,7,0,1,2 };

    cout << sol.findMin(nums);

    std::cin >> c;
}