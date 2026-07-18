// ok : map 으로 겨우... 
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


//:: timeout 
class _Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        
        int l = nums.size();
        unordered_map<int, vector<int>> m;
        vector<long long> ans(l, 0);

        for (int i = 0; i < l; ++i) {
            m[nums[i]].push_back(i);
        }

        for (auto& it : m) {

            if (it.second.size() > 1) {
                int vl = it.second.size();
                vector<long long> ac(vl, 0);
                for (int i = 0; i < vl; ++i) {
                    for (int j = 0; j < vl; ++j) {
                        ac[i] += abs(it.second[j] - it.second[i]);
                    }
                }

                for (int i = 0; i < vl; ++i) {
                    ans[it.second[i]] = ac[i];
                }
            }
            else {
                ans[it.second[0]] = 0;
            }
        }

        return ans;
    }
};

// Math 
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }
        vector<long long> res(n);
        for (const auto& p : groups) {
            const auto& group = p.second;
            long long total = accumulate(group.begin(), group.end(), 0LL);
            long long prefixTotal = 0;
            for (int i = 0; i < group.size(); i++) {
                res[group[i]] =
                    total - prefixTotal * 2 + group[i] * (2 * i - group.size());
                prefixTotal += group[i];
            }
        }
        return res;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1, 3, 1, 1, 2 };

    vector<long long> ans = sol.distance(nums);
    for (auto& it : ans) {
        cout << it << " ";
    }


    cin >> c;
}
