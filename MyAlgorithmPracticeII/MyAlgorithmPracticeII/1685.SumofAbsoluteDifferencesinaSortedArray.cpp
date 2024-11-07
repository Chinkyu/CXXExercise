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
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int ls = 0, rs = 0;
        int l = nums.size();

        vector<int> ans;

        for (auto& it : nums) {
            rs += it;
        }

        for (int i = 0; i < l; ++i) {
            ls += nums[i];
            rs -= nums[i];

            int diff = (((i + 1) * nums[i]) - ls) + (rs - (l - i - 1) * nums[i]);
            ans.push_back(diff);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> nums = { 1,4,6,8,10 };
    
    vector<int> ans = sol.getSumAbsoluteDifferences(nums);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}