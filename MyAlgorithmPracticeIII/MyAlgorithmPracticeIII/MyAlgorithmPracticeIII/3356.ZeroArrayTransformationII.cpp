// ok.. but slow... might be better solution. 
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
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = nums.size();
        int zero_cnt = 0;
        for (auto& it : nums) {
            if (it == 0) zero_cnt++;
        }

        if (zero_cnt == l) return 0;

        for (int i = 0; i < queries.size(); ++i) {
            int val = queries[i][2];
            for (int j = queries[i][0]; j <= queries[i][1]; ++j) {
                if (nums[j] > 0) {
                    nums[j] -= val;
                    if (nums[j] <= 0) {
                        zero_cnt++;
                        nums[j] = 0;
                        if (zero_cnt == l) return i + 1;
                    }
                }
            }
        }
        return -1;

    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,3,4,8 };
    vector<vector<int>> queries = { {0,1} ,{1,2},{2,3},{0,3} };

    vector<int> ans = sol.minDifference(nums, queries);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
