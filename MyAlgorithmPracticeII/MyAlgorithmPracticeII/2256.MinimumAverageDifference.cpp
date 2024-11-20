//  easy 
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

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int l = nums.size();

        if (l == 1) return 0;

        long long ls = nums[0];
        long long rs = 0;

        for (int i = 1; i < l; ++i) {
            rs += nums[i];
        }

        int lc = 1;
        int minv = abs(ls / lc - rs / (l - 1));
        int ans = 0;

        for (int i = 1; i < l; ++i) {
            ls += nums[i];
            rs -= nums[i];
            lc++;


            int v = (l - lc != 0) ? abs(ls / lc - rs / (l - lc)) : abs(ls/lc);
            if(v < minv) {
                minv = v;
                ans = i;
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1, 2, 3, 4, 5 };

    cout << sol.minimumAverageDifference(nums);

    cin >> c;
}