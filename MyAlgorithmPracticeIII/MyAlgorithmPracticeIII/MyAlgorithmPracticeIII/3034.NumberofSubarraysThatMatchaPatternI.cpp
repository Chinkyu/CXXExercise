// ok : do all check .. works 
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

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int l = nums.size();
        int m = pattern.size();
        vector<int> inc;

        for (int i = 0; i < l - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                inc.push_back(0);
            }
            else if (nums[i] < nums[i + 1]) {
                inc.push_back(1);
            }
            else {
                inc.push_back(-1);
            }
        }

        int ans = 0;
        for (int i = 0; i <= inc.size() - m; ++i) {

            bool isAllMatch = true;
            for (int j = i, k = 0; k < m; ++j, ++k) {
                if (inc[j] != pattern[k]) {
                    isAllMatch = false;
                    break;
                }
            }
            if (isAllMatch == true) ans++;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,2,3,4,5,6 };
    vector<int> pattern = { 1, 1 };

    cout << sol.countMatchingSubarrays(nums, pattern);


    cin >> c;
}
