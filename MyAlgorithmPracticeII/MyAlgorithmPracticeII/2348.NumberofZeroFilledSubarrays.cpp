//  easy
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
    long long sum(long long n) {
        long long s = 0;
        for (long long i = 1; i <= n; ++i) {
            s += i;
        }

        return s;
    }


    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;

        bool isZeroState = false;
        int zeroCount = 0;
        for (int i = 0; i < nums.size(); ++i) {

            if (isZeroState) {
                if (nums[i] != 0) {
                    isZeroState = false;
                    ans += sum(zeroCount);
                    zeroCount = 0;
                }
                else {
                    zeroCount++;
                }
            }
            else { // non zero state
                if (nums[i] == 0) {
                    isZeroState = true;
                    zeroCount = 1;
                }
            }
        }

        ans += sum(zeroCount);

        return ans;
    }
};



int main() {
    char c;
    Solution sol;

    cout << sol.sum(100000) << endl;

    vector<int> nums(100000, 0);

    cout << sol.zeroFilledSubarray(nums);

    cin >> c;
}