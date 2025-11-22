// strangely works if handle exception in zero case one error 
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
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l = nums.size();
        vector<int> v(l + 1, 0);
        int ans = 0;

        for (int i = 1; i < l + 1; ++i) {
            v[i] = v[i - 1] + nums[i - 1];
        }

        if (v[l] == 0 && goal == 0) {
            // l factorial
            for (int i = 1; i <= l; ++i) ans += i;
            return ans;
        }

        for (int i = 0; i < l + 2; ++i) {
            for (int j = i + 1; j < l + 1; ++j) {
                if (v[j] - v[i] == goal) ans++;
                if (v[j] - v[i] > goal) break;
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> nums = { 1,0,1,0,1 };

    cout << sol.numSubarraysWithSum(nums, 2);

    cin >> c;
}
