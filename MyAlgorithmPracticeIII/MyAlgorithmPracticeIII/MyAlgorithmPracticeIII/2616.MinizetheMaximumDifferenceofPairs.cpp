// see answer : bsearch 이게 풀린다는데 신기한데...... 진짜??  앞에서 해도 된다고.. 
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
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = nums[n - 1] - nums[0];

        while (left < right) {
            int mid = left + (right - left) / 2, pairs = 0;
            for (int i = 1; i < n; ++i) {
                if (mid >= nums[i] - nums[i - 1]) {
                    ++pairs, ++i;
                }
            }
            if (pairs >= p) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};


class _Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int l = nums.size();

        if (p <= 1) return 0;

        sort(nums.begin(), nums.end());

        vector<int> gap;
        int ans = 0;
        for (int i = 1; i < l; ++i) {
            gap.push_back(nums[i] - nums[i - 1]);
        }

        for (int i = 0; i < p; ++i) {
            int gmin = INT_MAX;
            for (int j = 0; j < nums.size(); ++j) {
                gmin = 
            }
        }

        return gap[p - 1];
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> numbers = { 2, 7, 11, 15 };

    vector<int> ans = sol.twoSum(numbers, 9);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
