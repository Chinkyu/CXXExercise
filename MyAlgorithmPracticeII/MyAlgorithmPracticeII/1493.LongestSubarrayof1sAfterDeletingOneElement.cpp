//  easy : brute force and debugging.. 
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
    int longestSubarray(vector<int>& nums) {
        int l = nums.size();

        int ans = 0;
        for(int i = 1; i < l - 1; ++i) {

            if(nums[i-1] == 1 && nums[i] != 1 && nums[i+1] == 1) {

                // left 1
                int j = i - 1;
                int ln = 0;
                while (j >= 0 && nums[j--] == 1) ln++;

                // right 1
                j = i + 1;
                int rn = 0;
                while (j < l && nums[j++] == 1) rn++;


                ans = max(ans, ln + rn);
            }

        }


            int single_num = 0;

            for (int i = 0; i < l; ++i) {
                if (nums[i] == 1) {
                    int n = 0;
                    while (i < l && nums[i] == 1) {
                        n++;
                        i++;
                    }
                    single_num = max(single_num, n);
                }
            }

            if (single_num == l) {
                single_num = single_num - 1;
            } 

            ans = max(ans, single_num);

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,1 };
    cout << sol.longestSubarray(nums);

    cin >> c;
}