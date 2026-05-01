// ok : 
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
    int longestConsecutive(vector<int>& nums) {
        int l = nums.size();

        if (l <= 1) return l;

        // need to remove duplication
        set<int> s;
        for (int i = 0; i < l; ++i) s.insert(nums[i]);

        vector<int> tnums;
        for (auto& it : s) tnums.push_back(it);


        sort(tnums.begin(), tnums.end());
        int pre = tnums[0];
        int ans = 1;
        int cnt = 1;


        for (int i = 1; i < tnums.size(); ++i) {
            if (tnums[i] == pre + 1) {
                cnt++;
                ans = max(ans, cnt);
            }
            else {
                cnt = 1;
            }
            pre = tnums[i];

        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 0,3,7,2,5,8,4,6,0,1 };

    cout << sol.longestConsecutive(nums);

    cin >> c;
}
