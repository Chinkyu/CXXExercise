// easy : 
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
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> c(n + 1, 0);
        c[1] = nums[0];
        for (int i = 2; i < n + 1; ++i) {
            c[i] = c[i - 1] + nums[i-1];
        }

        vector<int> s;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n + 1; ++j) {
                s.push_back(c[j] - c[i]);
            }
        }

        sort(s.begin(), s.end());

        int ans = 0;
        for (int i = left - 1; i < right; ++i) {
            ans += s[i];
            ans %= 1000000007;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    char c;
    vector<int> nums = { 1, 2, 3, 4 };

    cout << sol.rangeSum(nums, 4, 1, 5);

    cin >> c;
}
