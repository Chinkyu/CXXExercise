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
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1, i = n / 2, j = n, ans = 0;
        while (i >= 0 && j > n / 2) {
            if (nums[i] * 2 <= nums[j]) ans += 2, i--, j--;
            else i--;
        }
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,13,10,12,31 };

    cout << sol.countDistinctIntegers(nums);

    cin >> c;
}