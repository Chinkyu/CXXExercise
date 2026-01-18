// ok with sort
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
    vector<int> findDuplicates(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> ans;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == nums[i]) ans.push_back(nums[i]);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> numbers = { 2, 7, 11, 15 };

    vector<int> ans = sol.twoSum(numbers, 9);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
