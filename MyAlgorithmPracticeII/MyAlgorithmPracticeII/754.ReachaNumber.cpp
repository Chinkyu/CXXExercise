//  see anser : math
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
    int reachNumber(int target) {
        if (target < 0) {
            target = -target;
        }
        int step = 0;
        int sum = 0;
        while (true)
        {
            step++;
            sum = sum + step;
            if (sum == target)
            {
                return step;
            }
            else if (sum > target && (sum - target) % 2 == 0)
            {
                return step;
            }
        }
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