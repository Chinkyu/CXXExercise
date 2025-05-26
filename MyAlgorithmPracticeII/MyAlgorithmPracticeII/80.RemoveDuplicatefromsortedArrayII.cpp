//  ok
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
    int removeDuplicates(vector<int>& nums) {
        int l = nums.size();

        int c = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == c) {
                cnt++;
                if (cnt >= 3) nums[i] = INT_MAX;
            } else {
                c = nums[i];
                cnt = 1;
            }
        }

        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != INT_MAX) {
                nums[idx++] = nums[i];
            }
        }

        return idx;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,1,1,2,2,3 };

    cout << sol.removeDuplicates(nums);

    cin >> c;
}