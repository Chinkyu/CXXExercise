// ok : bsearch 

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

    int divSum(vector<int>& nums, int d) {

        int s = 0;
        for (auto& it : nums) {
            s += (it + (d - 1)) / d;
        }

        return s;
    }


    int smallestDivisor(vector<int>& nums, int threshold) {
        int szl = nums.size();
        sort(nums.begin(), nums.end());
        
        int l = 1; /*nums[0] */   // l should be from 1
        int r = nums[szl - 1];
        
        do {
            int m = (l + r) / 2;
            int ss = divSum(nums, m);

            //if (ss == threshold) return m;
            //else 
            if (ss <= threshold) {
                r = m;
            }
            else {
                l = m;
            }
        } while (l + 1 < r);

        if (divSum(nums, l) <= threshold) return l;
        return r;
    }
};

int main() {
    char c;
    Solution sol;

//    vector<int> nums = { 1,2,5,9 };
//    cout << sol.smallestDivisor(nums, 6);

    vector<int> nums = { 200,100,14 };
    cout << sol.smallestDivisor(nums, 10);


    cin >> c;
}
