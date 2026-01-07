// ok : using accumulation array 
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
    int minimizeSum(vector<int>& nums) {
        int l = nums.size();

        sort(nums.begin(), nums.end());

        if (l == 3) return 0;

        int min_gap = INT_MAX;
        min_gap = min(min_gap, nums[l - 1] - nums[2]);
        min_gap = min(min_gap, nums[l - 3] - nums[0]);
        min_gap = min(min_gap, nums[l - 2] - nums[1]);

        // can make new value same with existing => min == 0
        return min_gap;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<vector<int>> grid = { {1, 4},{2, 3} };
    //vector<vector<int>> grid = { {1, 3},{2, 4} };
    vector<vector<int>> grid = { {1, 1, 1} };

    cout << sol.canPartitionGrid(grid);

    cin >> c;
}
