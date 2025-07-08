// ok : median in even arry == 1/2 of middle two
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
#include <iostream>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long sum = 0;
        int l = nums.size();

        sort(nums.begin(), nums.end());

        int median = 0;
        if (l % 2 == 0) {
            median = (nums[l / 2] + nums[l / 2 - 1]) / 2;
        }
        else {
            median = nums[l / 2];
        }

        for (auto& it : nums) {
            sum += abs(it - median);
        }

        return sum;

    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1, 10, 2, 9 };


    cout << sol.minMoves2(nums);

    cin >> c;
}