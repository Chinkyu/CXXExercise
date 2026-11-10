// see answer... left and right ....  length.. 
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

/*
Explanation

We record non-decreasing lengths
from both directions using left and right.

left[i] is the length ending at i,
right[i] is the length starting at i.

By replacing one element,
we can connect two segments if A[i-1] <= A[i+1]

Take the maximum of left[i-1] + 1 + right[i+1],
and also consider max(left) + 1 bounded by n.

*/

class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int n = A.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++)
            if (A[i - 1] <= A[i])
                left[i] = left[i - 1] + 1;

        for (int i = n - 2; i >= 0; i--)
            if (A[i] <= A[i + 1])
                right[i] = right[i + 1] + 1;

        int res = min(n, *max_element(left.begin(), left.end()) + 1);
        for (int i = 1; i < n - 1; i++)
            if (A[i - 1] <= A[i + 1])
                res = max(res, left[i - 1] + 1 + right[i + 1]);
        return res;
    }
};


// 요거로도 안됨.. 
class _Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int l = nums.size();
        vector<int> v(l - 1, 0);

        if (l == 1) return 1;
        if (l == 2) return 2;

        for (int i = 1; i < l; ++i) {
            if (nums[i - 1] > nums[i]) {
                v[i - 1] = -1;
            }
        }

        int ans = 0;
        int st = 0, ed = 0;
        int minuscnt = 0;
        for (int i = 0; i < v.size(); ++i) {

            if (v[i] == -1) {
                minuscnt++;
            }

            if (minuscnt >= 2) {
                ed = i - 1;
                int mt = ed - st + 2;
                //if (0 < st || ed < v.size() - 1) {
                //    mt++;
                //}
                ans = max(ans, mt);
                st = i + 1;
            }

            if (i == v.size() - 1 && v[i] == 0) {
                ed = i;
                int mt = ed - st + 2;
                if (minuscnt <= 1 && ( 0 < st || ed < v.size() - 1)) {
                    mt++;
                }
                ans = max(ans, mt);
                st = i + 1;
            }
        }

        return ans;
    }
};



int main() {
    char c;
    Solution sol;

    vector<int> nums = { 2,2,2,2,2 };
    // { 1, 2, 3, 1, 2 };

    cout << sol.longestSubarray(nums);
    cin >> c;
}






