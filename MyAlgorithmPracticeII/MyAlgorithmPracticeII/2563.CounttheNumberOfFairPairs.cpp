// ¥‰∫√¿Ω : ???
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

// timeout 
class _Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int l = nums.size();
        sort(nums.begin(), nums.end());

        long long ans = 0;
        for (int i = 0; i < l - 1; ++i) {
            int tlow = lower - nums[i];
            int tupper = upper - nums[i];

            for (int j = i + 1; j < l; ++j) {
                if (tlow <= nums[j] && nums[j] <= tupper) ans++;
            }
        }

        return ans;
    }
};

// timeout
class __Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int l = nums.size();
        sort(nums.begin(), nums.end());

        long long ans = 0;

        for (int i = 0; i < l - 1; ++i) {
            int tlow = lower - nums[i];
            int tupper = upper - nums[i];
            int tl = l - i - 1;

            for (int j = i + 1; j < l; ++j) {
                if (nums[j] < tlow) tl--;
                else break;
            }

            for (int j = l - 1; i < j; --j) {
                if (tupper < nums[j]) tl--;
                else break;
            }

            ans += tl;
        }

        return ans;
    }
};


class Solution {
public:
    long long solve(vector<int>& nums, int x) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int id = upper_bound(nums.begin() + i + 1, nums.end(), x - nums[i]) - nums.begin();
            ans += (id - i);
        }
        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return solve(nums, upper) - solve(nums, lower - 1);
    }
};


int main() {
    Solution sol;
    char c;

    vector<int> nums = { 0,1,7,4,4,5 };

    cout << sol.countFairPairs(nums, 4, 6);

    cin >> c;
}
