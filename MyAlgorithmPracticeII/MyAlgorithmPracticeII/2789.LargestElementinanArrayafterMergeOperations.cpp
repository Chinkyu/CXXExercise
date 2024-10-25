// 답봤는데.. : 신기하게.... 
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
    long long maxArrayValue(vector<int>& nums) {
        long ans = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] > ans) {
                ans = nums[i];
            }
            else {
                ans += nums[i];
            }
        }
        return ans;
    }
};

class _Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        vector<long long> v;

        long long acc = 0;
        nums.push_back(0);
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] <= nums[i + 1]) {
                acc += nums[i];
            }
            else {
                acc += nums[i];
                v.push_back(acc);
                acc = 0;
            }
        }

        do {
            vector<long long> src = v;
            v.clear();

            src.push_back(0);
            for (int i = 0; i < src.size() - 1; ++i) {
                if (src[i] <= src[i + 1]) {
                    acc += src[i];
                }
                else {
                    acc += src[i];
                    v.push_back(acc);
                    acc = 0;
                }
            }

            if (src.size() - 1 == v.size()) break;

        } while (true);

        long long ans = 0;
        for (auto& it : v) {
            ans = max(ans, it);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> nums = { 40,15,35,98,77,79,24,62,53,84,97,16,30,22,49 }; // { 2, 3, 7, 9, 3 };

    cout << sol.maxArrayValue(nums);

    cin >> c;
}