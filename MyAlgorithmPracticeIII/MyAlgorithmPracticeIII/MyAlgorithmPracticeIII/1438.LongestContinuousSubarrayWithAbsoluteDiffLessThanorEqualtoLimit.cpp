// ok : two point sliding window

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
#include <bit>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int l = nums.size();
        int st = 0, ed = 0;
        multiset<int> ms;

        ms.insert(nums[0]);

        int ans = 0;

        for (int i = 0; i < l; ++i) {
            if (i > 0) {  // remove previous
                ms.erase(ms.find(nums[i- 1]));  // need to remove only one element
                st = i;
                if (ms.size() == 0) {
                    ms.insert(nums[i]);
                    ed = i;
                }
            }

            while(ed < l - 1) {
                int tmin = *ms.begin();
                int tmax = *ms.rbegin();

                int c = nums[ed + 1];
                if (c < tmin) tmin = c;
                if (c > tmax) tmax = c;

                if (tmax - tmin <= limit) {
                    ms.insert(c);
                    ++ed;
                    
                }
                else {
                    break;
                }
            }

            ans = max(ans, ed - st + 1);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 2, 2, 2, 4, 4, 2, 5, 5, 5, 5, 5, 2 };
    //{ 8,2,4,7 };

    cout << sol.longestSubarray(nums, 2);

    cin >> c;
}

