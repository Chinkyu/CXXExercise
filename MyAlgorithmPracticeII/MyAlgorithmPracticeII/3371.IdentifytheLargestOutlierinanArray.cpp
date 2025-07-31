// ok : see hint 
// (total_sum - outlier_candicate)/2  is exist  its outlier


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
#include <cmath>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int l = nums.size();
        unordered_map<int, int> m;
        int sum = 0;

        for (auto& it : nums) {
            sum += it;
            m[it]++;
        }

        int ans = INT_MIN;
        for (int i = 0; i < l; ++i) {
            int sub_sum = sum - nums[i];
            if (sub_sum % 2 == 0) {
                int s = sub_sum / 2;
                if (s == nums[i]) {
                    if (m[s] >= 2) ans = max(ans, s);
                }
                else {  // s != nums[i]
                    if (m[s] >= 1) ans = max(ans, nums[i]);
                }
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    //vector<int> nums = { 2,3,5,10 };
    vector<int> nums = { -2,-1,-3,-6,4 };

    cout << sol.getLargestOutlier(nums);

    cin >> c;
}