//  referenced : maintain leftmax,  rightmin
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


// wrong
class _Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int l = nums.size();

        vector<int> c(l, 0);
        c[0] = 0;

        int cnt = 0;
        for (int i = 1; i < l; ++i) {
            if (nums[i - 1] >= nums[i]) {
                cnt++;
            }
            c[i] = cnt;
        }

        int ans = 0;
        for (int i = 1; i < l - 1; ++i) {
            if (c[i] == 0 && c[l - 1] == 0) {
                ans += 2;
            }
            else if (c[i - 1] == c[i] && c[i] == c[i + 1]) {
                ans ++;
            }

        }

        return ans;
    }
};


class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int l = nums.size();

        vector<int> LeftMax(l, 0), RightMin(l, 0);

        int tmax = nums[0];
        for (int i = 0; i < l; ++i) {
            tmax = max(tmax, nums[i]);
            LeftMax[i] = tmax;
        }

        int tmin = nums[l - 1];
        for (int i = l - 1; i >= 0; i--) {
            tmin = min(tmin, nums[i]);
            RightMin[i] = tmin;
        }

        int ans = 0;
        for (int i = 1; i < l - 1; ++i) {
            if (LeftMax[i - 1] < nums[i] && nums[i] < RightMin[i + 1]) {
                ans += 2;
            }
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans++;
            }

        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,2,3 };

    cout << sol.sumOfBeauties(nums);

    cin >> c;
}