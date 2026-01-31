// refer answer but may need map

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
#include <random>
#include <chrono>
#include <iterator>

using namespace std;


// 문제가 좀 이상함... 이렇게 되는데.. map을 써야 할것 같음...
class Solution {
public:
    int countWays(vector<int>& nums) {
        int l = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        int cur = -1;

        /*
        if start from non 0 : include nonselected
        if index + 1 > num[i]  when change num : ans ++
        */


        if (nums[0] != 0) ans++; // zero selection

        for (int i = 0; i < l; ++i) {
            if (i == l - 1) {
                if (i + 1 > nums[i]) ans++;
            }
            else if (nums[i + 1] != nums[i]) {
                if (i + 1 > nums[i] && i + 1 < nums[i+1]) {
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

    vector<int> nums = { 6,0,3,3,6,7,2,7 };
    cout << sol.countWays(nums);


    cin >> c;
}
