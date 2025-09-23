// see answer : skip
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
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int end1 = nums1[n - 1], end2 = nums2[n - 1];
        int dp1 = 0, dp2 = 0;
        int maxi = max(end1, end2), mini = min(end1, end2);
        for (int i = 0; i < n; ++i) {
            int a = nums1[i], b = nums2[i];
            if (max(a, b) > maxi || min(a, b) > mini) return -1;
            if (a > end1 || b > end2) ++dp1;
            if (a > end2 || b > end1) ++dp2;
        }
        return min(dp1, dp2);
    }
};

int main() {
    Solution sol;
    char c;

    vector<int> nums1 = { 1, 2 };
    vector<int> nums2 = { -2, -1};
    vector<int> nums3 = { -1, 2 };
    vector<int> nums4 = { 0, 2 };

    cout << sol.fourSumCount(nums1, nums2, nums3, nums4);

    cin >> c;
}
