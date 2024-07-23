// Easy
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int> ans;

        for (int i = 0; i < k; ++i) ms.insert(nums[i]);

        ans.push_back(*ms.rbegin());


        for (int i = k; i < nums.size(); ++i) {
            ms.insert(nums[i]);
            ms.erase(ms.find(nums[i - k]));

            ans.push_back(*ms.rbegin());
        }

        return ans;
    }
};

int main() {
    Solution sol;
    char c;

    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };

    vector<int> ans = sol.maxSlidingWindow(nums, 3);


    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
