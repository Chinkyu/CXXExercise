//see answer :  kadane algorithm??? 

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
#include <chrono>
#include <iterator>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = LLONG_MIN;
        vector<long long> psum{ 0 };
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            psum.push_back(psum.back() + nums[i]); // Prefix Sum
            if (auto it = m.find(nums[i] - k); it != end(m))
                res = max(res, psum[i + 1] - psum[it->second]); // n - k
            if (auto it = m.find(nums[i] + k); it != end(m))
                res = max(res, psum[i + 1] - psum[it->second]); // n + k
            if (auto it = m.find(nums[i]); it == end(m) || psum[i] - psum[it->second] <= 0)
                m[nums[i]] = i; // Kadane
        }
        return res == LLONG_MIN ? 0 : res;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "00011000";
    cout << sol.minFlipsMonoIncr(s);


    cin >> c;
}
