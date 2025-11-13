// easy : 
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
    int minPairSum(vector<int>& nums) {
        int l = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;

        for (int i = 0; i < l / 2; ++i) {
            ans = max(ans, nums[i] + nums[l - i - 1]);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<int> asteroids = {5, 10, -5};
    vector<int> starPos = { 1, 0 };
    vector<int> homePos = { 2, 3 };
    vector<int> rowCosts = { 5, 4, 3 };
    vector<int> colCosts = { 8, 2, 6, 7 };

    cout << sol.minCost(starPos, homePos, rowCosts, colCosts);


    //cout << "Test  application";

    cin >> c;
}
