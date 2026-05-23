// strangely easy 
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
#include <bit>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = nums.size();

        if (l == 1) return 0;

        for (int i = 0; i < l; ++i) {
            int pre = (i <= 0) ? INT_MIN : nums[i - 1];
            int post = (i >= l - 1) ? INT_MIN : nums[i + 1];

            if (pre < nums[i] && nums[i] > post) return i;
        }

        return -1;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1, 2, 3, 1 };

    cout << sol.findPeakElement(nums);

    cin >> c;
}

