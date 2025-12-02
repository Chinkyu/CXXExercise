// ok  : timeout  -> move forward   -> and -> move backwoard and forward and count
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

// timeout 
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = nums.size();
        vector<int> cv(l + 1, 0);

        int ocnt = 0;
        for (int i = 0; i < l; ++i) {
            if (nums[i] % 2 == 1) ocnt++;
            cv[i + 1] = ocnt;
        }

        int ans = 0;
        int st = 0, ed = 0;

        for (int j = 0; j < l + 1; ++j) {
            if (cv[j] - cv[0] == k) ans++;
            if (cv[j] - cv[0] > k) {
                ed = j - 1;
                break;
            }
        }

        for (int i = 1; i < l; ++i) {
            // roll back till k
            while (cv[ed] - cv[i] >= k) ed--;

            while(cv[ed] - cv[i] <= k ) {
                if (cv[ed] - cv[i] == k) ans++;
                if (ed < l) {
                    ed++;
                }
                else {
                    break;
                }
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<int> nums = { 3, -1, -5, 2, 5, -9 };
    vector<int> nums = { 0 };

    cout << sol.maxStrength(nums);


    cin >> c;
}
