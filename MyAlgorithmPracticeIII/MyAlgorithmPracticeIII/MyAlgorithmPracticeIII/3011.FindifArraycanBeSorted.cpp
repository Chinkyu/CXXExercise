// ok : partial sort if number of 1 are same. 
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
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            n &= (n - 1); // Clears the rightmost set bit
            count++;
        }
        return count;
    }

    bool canSortArray(vector<int>& nums) {
        int l = nums.size();
        vector<int> n;
        for (auto& it : nums) {
            n.push_back(countSetBits(it));
        }

        vector<int> sn = nums;
        sort(sn.begin(), sn.end());

        int pre = n[0];
        int st = 0, ed = 0;
        for (int i = 1; i < l; ++i) {
            if (pre != n[i]) {
                ed = i - 1;

                if (st != ed) {
                    sort(nums.begin() + st, nums.begin() + ed + 1);
                }
                st = i;
                pre = n[i];
            }
        }

        ed = l - 1;

        if (st != ed) {
            sort(nums.begin() + st, nums.begin() + ed + 1);
        }

        if (nums == sn) {
            return true;
        }

        return false;


    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 8, 4, 2, 30, 15 };

    cout << sol.canSortArray(nums);

    cin >> c;
}
