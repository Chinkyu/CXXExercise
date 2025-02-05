// Easy : straight forward

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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        for (auto& it : nums) {
            m[it]++;
        }

        vector<vector<int>> v;
        for (auto& it : m) {
            v.push_back({ it.first, it.second });
        }

        sort(v.begin(), v.end(), [](vector<int>& l, vector<int>& r) {
            return l[1] > r[1];
            });

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(v[i][0]);
        }

        return ans;

    }
};

int main() {
    char c;
    Solution sol;
    vector<int> nums = { 1,1,1,2,2, 2, 2,3 };

    vector<int> ans = sol.topKFrequent(nums, 2);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}