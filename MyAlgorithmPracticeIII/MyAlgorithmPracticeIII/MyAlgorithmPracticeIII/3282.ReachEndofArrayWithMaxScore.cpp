// 오... 이거는 intuitive 하게 생각해서 푼것인데.. 답이네..
// adding current max ...  is optimal 
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
#include <random>

using namespace std;

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int l = nums.size();
        long long ans = 0;

        int tmax = nums[0];
        for (int i = 0; i < l - 1; ++i) {
            tmax = max(tmax, nums[i]);
            ans += tmax;
        }

        return ans;
    }
};



int main() {
    char c;
    Solution sol;

    vector<int> nums1 = { 18,11,24,9,10,11,7,29,16 };
    vector<int> nums2 = { 28,26,27,4,2,19,23,1,2 };

    vector<long long> ans = sol.findMaxSum(nums1, nums2, 1);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
