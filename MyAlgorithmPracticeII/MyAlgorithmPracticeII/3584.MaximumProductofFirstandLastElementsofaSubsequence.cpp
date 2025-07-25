// ok : sliding window ans  max and min till now (생각을 잘 하면 쉽게 나올 수 있는 답인데..
// 생각이 이렇게 하기가 쉽지 않음... 

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
    long long maximumProduct(vector<int>& nums, int m) {
        int l = nums.size();
        int smin = nums[0];
        int smax = nums[0];
        long long ans = smin * (long long)nums[m - 1];

        if (m == 1) {
            for (int i = 1; i < l; ++i) {
                ans = fmax(ans, (long long)nums[i] * (long long)nums[i]);
            }

            return ans;
        }


        for (int i = m; i < l; ++i) {
            smin = min(smin, nums[i - m + 1]);
            smax = max(smax, nums[i - m + 1]);

            ans = fmax(ans, smin * (long long)nums[i]);
            ans = fmax(ans, smax* (long long)nums[i]);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 0,-9,2,-9,-3,-10,2 };

    cout << sol.maximumProduct(nums, 3);

    cin >> c;
}