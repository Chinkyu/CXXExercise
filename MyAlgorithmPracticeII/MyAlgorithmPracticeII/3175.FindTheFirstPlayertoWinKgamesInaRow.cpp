//  ¥‰∫√¿Ω : 
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
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        if (k >= n)
        {
            int m = 0, ans = -1;
            for (int i = 0; i < n; ++i)
            {
                if (skills[i] > m)
                {
                    m = skills[i];
                    ans = i;
                }
            }
            return ans;
        }
        int sum = 0, ans = 0;
        for (int i = 1; i < n; ++i)
        {
            if (skills[ans] > skills[i])
                ++sum;
            else
            {
                ans = i;
                sum = 1;
            }
            if (sum == k)
                return ans;
        }
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<int> nums1 = { 1, 7, 5 };
    //vector<int> nums2 = { 2, 3, 5 };
    vector<int> nums1 = { 1, 28, 21 };
    vector<int> nums2 = { 9, 21, 20 };

    cout << sol.minAbsoluteSumDiff(nums1, nums2);

    cin >> c;
}