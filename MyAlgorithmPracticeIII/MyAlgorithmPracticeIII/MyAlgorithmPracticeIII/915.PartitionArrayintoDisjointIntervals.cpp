// Ok 
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
    int partitionDisjoint(vector<int>& nums) {
        int l = nums.size();
        multiset<int> ls, rs;

        //int ans = 0;

        // reset 
        ls.insert(nums[0]);
        for (int i = 1; i < l; ++i) {
            rs.insert(nums[i]);
        }

        if (*ls.rbegin() <= *rs.begin()) {
            return 1;
        }

        for (int i = 1; i < l - 1; ++i) {
            ls.insert(nums[i]);
            rs.erase(rs.find(nums[i]));

            if (*ls.rbegin() <= *rs.begin()) {
                return i + 1;
            }
        }

        return -1;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,1,1,0,6,12 };
    // { 1, 2, 3, 3, 2, 2 };

    cout << sol.partitionDisjoint(nums);

    cin >> c;
}
