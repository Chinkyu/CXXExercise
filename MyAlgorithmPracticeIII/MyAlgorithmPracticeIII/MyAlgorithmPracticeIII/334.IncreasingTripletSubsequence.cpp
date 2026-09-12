// ok : use set 
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
    bool increasingTriplet(vector<int>& nums) {
        int l = nums.size();
        multiset<int> ls, rs;

        ls.insert(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            rs.insert(nums[i]);
        }

        // check 
        for (int i = 1; i < nums.size() - 1; ++i) {
            int m = nums[i];
            //rs.erase(m);

            // erase only one elements
            auto it = rs.find(m);
            if (it != rs.end()) {
                rs.erase(it);
            }


            // check 
            if (*ls.begin() < m && m < *rs.rbegin()) {
                return true;
            }
            ls.insert(m);
        }

        return false;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "1101";
    cout << sol.numSteps(s);

    cin >> c;
}
