// Tricky.. : First count by removing right and remove from left one only
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

    int countLower(vector<int>& nums, int li, int lr, int left) {

        long long ans = 0;
        long long c = 0;
        for (int i = li; i <= lr; ++i) {
            if (nums[i] < left) {
                c++;
            }
            else {
                ans += (c * (c + 1)) / 2;
                c = 0;
            }
        }

        if (c > 0) {
            ans += (c * (c + 1)) / 2;
        }

        return ans;
    }


    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int l = nums.size();
        long long ans = 0;

        long long c = 0;
        for (int i = 0; i < l; ++i) {
            if (nums[i] <= right) {
                c++;
            }
            else {
                ans += (c * (c + 1)) / 2;
                ans -= countLower(nums, i - c, i - 1, left);
                c = 0;
            }
        }

        if (c > 0) {
            ans += (c * (c + 1)) / 2;
            ans -= countLower(nums, l - c, l - 1, left);
        }
        
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> nums = { 2, 1, 4, 3 };
    cout << sol.numSubarrayBoundedMax(nums, 2, 3);

    cin >> c;
}