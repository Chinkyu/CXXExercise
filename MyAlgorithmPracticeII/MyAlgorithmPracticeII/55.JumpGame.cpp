// see anser : 심박하게 풀었다.... 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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

// see answer : maxReach
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};

// timeout 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = nums.size();
        set<int> runner;

        if (l == 1) return true;

        runner.insert(0);

        while (runner.size() != 0) {
            set<int> n_runner;
            for (auto rit = runner.rbegin(); rit != runner.rend(); ++rit) {
                int mj = nums[*rit];
                for (int i = mj; i > 0; --i) {
                    if (i + *rit == l - 1) {
                        return true;
                    }
                    if (i + *rit < l - 1 && nums[i + *rit] != 0) {
                        //cout << i + *rit << " ";
                        n_runner.insert(i + *rit);
                    }
                }
            }
            runner = n_runner;
        }

        return false;
    }
};


int main() {
    Solution sol;
    char c;

    vector<int> nums = { 3,2,1,0,4 };
    cout << sol.canJump(nums);

    cin >> c;
}
