// see solution : dynamnic
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
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> tails(nums.size(), 0);
        int size = 0;

        for (int x : nums) {
            int i = 0, j = size;
            while (i != j) {
                int m = (i + j) / 2;
                if (tails[m] < x)
                    i = m + 1;
                else
                    j = m;
            }
            tails[i] = x;
            if (i == size) ++size;
        }
        return size;
    }
};



class _Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int l = nums.size();
        vector<int> v = nums;
        vector<int> c(l, 1);
        int cnt = 0;

        for (int i = 1; i < l; ++i) {
            for (int j = 0; j < i; ++j) {
                if (v[j] < nums[i]) {
                    v[j] = nums[i];
                    c[j]++;
                }
            }
        }

        // find max
        int tmax = 0;
        for (int i = 0; i < l; ++i) {
            tmax = max(tmax, c[i]);
        }

        return tmax;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<int> nums = { 10,9,2,5,3,7,101,18 };
    vector<int> nums = { 0,1,0,3,2,3 };

    cout << sol.lengthOfLIS(nums);

    cin >> c;
}