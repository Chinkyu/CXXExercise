// easy
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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;
        int l = nums1.size();

        int ans = 0;
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < l; ++j) {
                m[nums1[i] + nums2[j]]++;
            }
        }

        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < l; ++j) {
                ans += m[(nums3[i] + nums4[j]) * -1];
            }
        }
        return ans;
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
