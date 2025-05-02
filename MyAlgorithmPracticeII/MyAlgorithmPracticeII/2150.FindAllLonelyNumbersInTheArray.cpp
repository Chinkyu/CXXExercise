//  OK. 
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
#include <set>
#include <list>
#include <regex>
#include <memory>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int, int> m;

        for (auto it : nums) {
            m[it]++;
        }

        vector<int> ans;
        for (auto it : m) {
            if (it.second == 1 && m[it.first - 1] == 0 && m[it.first + 1] == 0) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 10, 6, 5, 8 };

    vector<int> ans = sol.findLonely(nums);

    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}