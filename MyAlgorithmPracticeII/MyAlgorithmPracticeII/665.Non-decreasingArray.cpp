// ok.  : If there is drop..    check ith  and i+1th non valid case check both. 
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
    bool checkPossibility(vector<int>& nums) {
        int l = nums.size();

        int drop_cnt = 0;
        for (int i = 0; i < l - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                // nums[i] is wrong 
                // nums[i+1] is wrong
                if ((0 < i && nums[i - 1] > nums[i + 1]) &&
                    (i + 2 < l && nums[i] > nums[i + 2])) return false;
                drop_cnt++;

            }
            if (drop_cnt >= 2) return false;
        }

        return true;
    }
};

int main() {
    Solution sol;
    char c;
    vector<int> nums = { 4, 2, 3 };

    cout << sol.checkPossibility(nums);

    cin >> c;
}
