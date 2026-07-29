// ok
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
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if (nums.size() <= 1) return 0;

        int max_gap = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] > max_gap) {
                max_gap = nums[i] - nums[i - 1];
            }
        }

        return max_gap;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> v = { 1, 2, 3, 4 };

    sol.buildBTS(v, 0, v.size() - 1);

    //    cout << sol.angleClock(1, 57);


    cin >> c;
}
