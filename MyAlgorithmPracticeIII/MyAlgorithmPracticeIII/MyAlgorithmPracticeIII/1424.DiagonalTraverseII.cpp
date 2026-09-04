// see answer : monotonic stack 
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
#include <numeric>

using namespace std;


// timeout.. => do it tomorrow..   sum, raw, val....  => repositioning
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int ms = 0;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                ms = max(ms, i + j);
            }
        }

        vector<int> ans;

        for (int i = 0; i <= ms; ++i) {
            //int sum = 0;
            for (int j = ms; j >= 0; --j) {
                int k = i - j;

                if (j < nums.size() && k < nums[j].size()) {
                    //sum += nums[j][k];
                    ans.push_back(nums[j][k]);
                }
            }
            //ans.push_back(sum);
        }

        return ans;
    }
};

int main() {
    char c;

    Solution sol;

    vector<vector<int>> nums = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };

    vector<int> ans = sol.findDiagonalOrder(nums);

    for (auto& it : ans) {
        cout << it << " ";
    }


    cin >> c;
}
