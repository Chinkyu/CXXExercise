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

using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums)
    {
        int numsIndex = 0;
        int groupsIndex = 0;

        while (numsIndex < nums.size() && groupsIndex < groups.size())
        {
            // Try to match as many members of the current group as possible
            int matchCount = 0;
            while (numsIndex + matchCount < nums.size() &&
                matchCount < groups[groupsIndex].size() &&
                nums[numsIndex + matchCount] == groups[groupsIndex][matchCount])
                ++matchCount;

            // Did we match the entire current group?
            if (matchCount == groups[groupsIndex].size())
            {
                // the group was matched
                ++groupsIndex;

                // since there must not be overlap between groups
                // we must match the next group at next element in nums
                numsIndex += matchCount;
            }
            else
            {
                // unsucessful in matching all elements of current group
                // retry matching the group from start at next element in nums
                ++numsIndex;
            }
        }

        return groupsIndex == groups.size();
    }
};

int main() {
    char c;
    Solution sol;
    //vector<int> nums = { 3, -1, -5, 2, 5, -9 };
    vector<int> nums = { 0 };

    cout << sol.maxStrength(nums);


    cin >> c;
}
