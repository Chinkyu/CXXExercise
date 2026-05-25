// ok : might have better using sliding window
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
    int countCompleteSubarrays(vector<int>& nums) {
        int l = nums.size();

        unordered_map<int, int> gm;
        for (int i = 0; i < l; ++i) {
            gm[nums[i]]++;
        }

        int tsize = gm.size();
        int ans = 0;
        for (int i = 0; i < l; ++i) {
            unordered_map<int, int> m;
            for (int j = i; j < l; ++j) {
                m[nums[j]]++;

                if (m.size() == tsize) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1, 2, 3, 1 };

    cout << sol.findPeakElement(nums);

    cin >> c;
}

