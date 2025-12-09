// 문제가 좀 이상함.... 
//   
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
    int sortPermutation(vector<int>& nums) {
        int l = nums.size();
        vector<int> sn = nums;
        sort(sn.begin(), sn.end());

        int ans = 0xFFFF;
        for (int i = 0; i < l; ++i) {
            if (sn[i] != nums[i]) ans &= nums[i];
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = {0, 3, 2, 1};

    cout << sol.sortPermutation(nums);

    cin >> c;
}
