// ok..  use rotate api
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
    void rotate(vector<int>& nums, int k) {
        int l = nums.size();
        k %= l;

        std::rotate(nums.begin(), nums.begin() + (l - k), nums.end());
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums{ 5,2,7,9,16 };
    cout << sol.longestSubarray(nums);

    cin >> c;
}
