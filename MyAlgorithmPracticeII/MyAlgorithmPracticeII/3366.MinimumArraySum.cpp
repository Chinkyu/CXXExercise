// see answer : dp memo
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
    long long dp[101][101][101];
    int find(vector<int>& nums, int index, int k, int op1, int op2) {
        if (index >= nums.size()) {
            return 0;
        }
        if (dp[index][op1][op2] != -1) {
            return dp[index][op1][op2];
        }
        int ans = nums[index] + find(nums, index + 1, k, op1, op2);
        if (op1 > 0) {
            ans = min(ans, (nums[index] + 1) / 2 + find(nums, index + 1, k, op1 - 1, op2));
        }
        if (op2 > 0 && (nums[index] >= k)) {
            ans = min(ans, (nums[index] - k) + find(nums, index + 1, k, op1, op2 - 1));
        }
        if (op1 > 0 && op2 > 0) {
            int divided = (nums[index] + 1) / 2;
            if (divided >= k) {
                ans = min(ans, divided - k + find(nums, index + 1, k, op1 - 1, op2 - 1));
            }
        }
        if (op1 > 0 && op2 > 0 && nums[index] >= k) {
            int subtracted = nums[index] - k;
            ans = min(ans, (subtracted + 1) / 2 + find(nums, index + 1, k, op1 - 1, op2 - 1));
        }
        return dp[index][op1][op2] = ans;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp, -1, sizeof(dp));
        return find(nums, 0, k, op1, op2);
    }
};
int main() {
    Solution sol;
    char c;
    string s1 = "leetcode";
    string s2 = "programs";

    cout << sol.smallestEquivalentString(s1, s2, "sourcecode");

    cin >> c;
}
