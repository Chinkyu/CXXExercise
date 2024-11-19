//  easy 
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
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p, m;

        for (auto& it : nums) {
            if (it > 0) {
                p.push_back(it);
            }
            else {
                m.push_back(it);
            }
        }

        vector<int> ans;
        for (int i = 0; i < p.size(); ++i) {
            ans.push_back(p[i]);
            ans.push_back(m[i]);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 3,1,-2,-5,2,-4 };

    vector<int> ans = sol.rearrangeArray(nums);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}