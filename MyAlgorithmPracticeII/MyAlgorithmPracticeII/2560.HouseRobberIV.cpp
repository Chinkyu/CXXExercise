//  ¥‰∫√¿Ω  : 
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
    int minCapability(vector<int>& nums, int k) {
        int l = 1, r = 1000000000;
        while (l < r) {
            int m = (l + r) / 2, take = 0;
            for (int i = 0; i < nums.size() && take < k; ++i) {
                take += nums[i] <= m;
                i += nums[i] <= m;
            }
            if (take < k)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<int> nums = { 2, 1, 3, 2, 1 };
    vector<int> nums = { 3, 1, 2 };


    cout << sol.minimumOperations(nums);

    cin >> c;
}