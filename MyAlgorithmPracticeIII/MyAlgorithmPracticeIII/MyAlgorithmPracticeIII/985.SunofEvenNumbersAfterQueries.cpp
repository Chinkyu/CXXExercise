// ok : 
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
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int esum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) esum += nums[i];
        }

        // even(old) -> even(new)  = add delta
        // even(old) -> old(new) = - old
        // odd(old) -> even(new) = + new
        // odd(old) -> odd(old) = 0
        vector<int> ans;
        for(auto &it : queries) {
            int oldv = nums[it[1]];
            int newv = oldv + it[0];
            nums[it[1]] = newv;

            if (oldv % 2 == 0 && newv % 2 == 0) { esum += newv - oldv;  ans.push_back(esum); }
            if (oldv % 2 == 0 && newv % 2 != 0) { esum -= oldv;  ans.push_back(esum); }
            if (oldv % 2 != 0 && newv % 2 == 0) { esum += newv;  ans.push_back(esum); }
            if (oldv % 2 != 0 && newv % 2 != 0) { ans.push_back(esum); }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,2 ,3 ,4 };
    vector<vector<int>> queries = { {1,0}, {-3,1}, {-4,0}, {2,3} };

    vector<int> ans = sol.sumEvenAfterQueries(nums, queries);

    for (auto& it : ans) {
        cout << it << " ";
    }


    cin >> c;
}
