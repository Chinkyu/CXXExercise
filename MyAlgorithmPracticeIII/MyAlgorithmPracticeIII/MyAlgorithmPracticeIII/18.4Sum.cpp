// see answer 
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

// timeout  ->  forward and backwoard after  sort
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> s;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            for (int j = i + 1; j < n - 2; ++j) {
                for (int k = j + 1; k < n - 1; ++k) {
                    for (int l = k + 1; l < n; ++l) {
                        if (target == (long long)nums[i] + nums[j] + nums[k] + nums[l]) {
                            s.insert({ nums[i], nums[j], nums[k], nums[l]});
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for (auto& it : s) {
            ans.push_back(it);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,0,-1,0,-2,2 };

    vector<vector<int>> ans = sol.fourSum(nums, 0);

    for (auto& it : ans) {
        cout << it[0] << "," << it[1] << "," << it[2] << "." << it[3];
    }


    cin >> c;
}
