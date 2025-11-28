// ok  : tricky with zero ... 
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
    long long maxStrength(vector<int>& nums) {
        long long ans = 1;
        sort(nums.begin(), nums.end(), [](int l, int r) {
            return abs(l) < abs(r);
            });

        int mcount = 0;
        int first_minus = 0;
        int zcount = 0;
        for (auto& it : nums) {
            if (it < 0) {
                if (first_minus == 0) first_minus = it;
                mcount++;
            }
            if (it == 0) {
                zcount++;
                continue;
            }
            ans *= it;
        }

        if (zcount > 0 && nums.size() - zcount == 0) return 0;

        if (ans <= 0) {
            if (zcount > 0 && nums.size() - zcount == 1) return 0;
            if (nums.size() == 1) return nums[0];
            ans /= first_minus;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<int> nums = { 3, -1, -5, 2, 5, -9 };
    vector<int> nums = { 0 };

    cout << sol.maxStrength(nums);


    cin >> c;
}
