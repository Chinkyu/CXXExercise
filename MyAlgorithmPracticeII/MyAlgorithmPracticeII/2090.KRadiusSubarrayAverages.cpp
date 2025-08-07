// ok : debugging 
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <cmath>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int l = nums.size();
        int ss = k * 2 + 1;

        vector<int> ans(l, -1);

        if (ss > l) return ans;

        long long sum = 0;
        for (int i = 0; i < ss; ++i) sum += nums[i];
        ans[k] = sum / ss;
        for (int i = 1, j = k + 1; i < l - ss + 1; ++i, ++j) {
            sum -= nums[i - 1];
            sum += nums[ss + i - 1];
            ans[j] = sum / ss;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> nums = { 7,4,3,9,1,8,5,2,6 };

    vector<int> ans =  sol.getAverages(nums, 3);
    for (int& it : ans) {
        cout << it << " ";
    }

    std::cin >> c;
}