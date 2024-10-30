// Midim : 뒤부분 Max frequency 를 유지 할 필요 없음... 
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
#include <functional>

using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        int max_num = -1, max_val = -1;

        unordered_map<int, int> lm, rm;

        for (int i = 0; i < nums.size(); ++i) {
            rm[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); ++i) {
            lm[nums[i]]++;
            rm[nums[i]]--;
            if (rm[nums[i]] == 0) rm.erase(nums[i]);
            if (lm[nums[i]] > max_val) {
                max_val = lm[nums[i]];
                max_num = nums[i];
            }

            if (lm[max_num] * 2 > (i + 1) &&
                rm[max_num] * 2 > (nums.size() - i - 1)) {
                return i;
            }
        }
        
        return -1;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> nums = { 2,1,3,1,1,1,7,1,2,1 };

    cout << sol.minimumIndex(nums);

    cin >> c;
}