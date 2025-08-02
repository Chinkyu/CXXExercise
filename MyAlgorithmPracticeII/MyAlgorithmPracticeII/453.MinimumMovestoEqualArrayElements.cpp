// ok : suprise this pass.... just find delta from lowese
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <cmath>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {

        // increase all except one is decrease one 
        sort(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 1; i < nums.size(); ++i) {
            ans += nums[i] - nums[0];
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> coords = { {1, 1}, {1, 2}, {3, 2}, {3, 3} };

    std::cout << sol.maxArea(coords);
    std::cin >> c;
}