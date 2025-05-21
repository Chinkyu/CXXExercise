// Can't understand description with answer
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
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> asnd;

        int pre = 0;
        for (auto& it : nums) {
            if (it > pre) {
                asnd.push_back(1);
            }
            else {
                asnd.push_back(-1);
            }
            pre = it;
        }

        vector<int> ans;
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            if (asnd[i] == -1) cnt++;
        }

        if (cnt <= 0) {
            ans.push_back(nums[k - 1]);
        }
        else {
            ans.push_back(-1);
        }

        for (int i = k; i < nums.size(); ++i) {
            if (asnd[i - k + 1] == -1) cnt--;
            if (asnd[i] == -1) cnt++;

            if (cnt <= 0) {
                ans.push_back(nums[i]);
            }
            else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    //vector<int> nums = { 1,2,3,4,3,2,5 };
    //vector<int> nums = { 2,2,2,2,2 };
    vector<int> nums = { 3,2,3,2,3,2 };

    vector<int> ans = sol.resultsArray(nums, 2);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}