// ok... :  *=  zero count + 1
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
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int l = nums.size();


        long long ans = 1;

        int i = 0;
        // skip first 0
        while (i < l && nums[i] == 0) i++;

        if (i == l) return 0;

        int cnt = 0;
        for (i++; i < l; ++i) {
            if (nums[i] == 1) {
                ans *= cnt + 1;
                ans %= 1000000007;
                cnt = 0;
            }
            else {  // 0
                cnt++;
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 0, 1, 0, 0, 1 };

    cout << sol.numberOfGoodSubarraySplits(nums);

    cin >> c;
}