// see answer : accumulation array using   size 101 and to max query.... really??  
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

// accumulation array using 
int cnt[100001][101] = {};
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& qs) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
            for (int j = 1; j <= 100; ++j)
                cnt[i + 1][j] = cnt[i][j] + (nums[i] == j);
        for (int i = 0; i < qs.size(); ++i) {
            int prev = 0, delta = INT_MAX;
            for (int j = 1; j <= 100; ++j)
                if (cnt[qs[i][1] + 1][j] - cnt[qs[i][0]][j]) {
                    delta = min(delta, prev == 0 ? INT_MAX : j - prev);
                    prev = j;
                }
            res.push_back(delta == INT_MAX ? -1 : delta);
        }
        return res;
    }
};


// timeout 
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int> ans;

        for (auto& it: queries) {

            set<int> s;
            for (int i = it[0]; i <= it[1]; ++i) {
                s.insert(abs(nums[i]));
            }
            int vl = s.size();
            if (s.size() <= 1) {
                ans.push_back(-1);
                continue;
            }

            int t_min = INT_MAX;
            auto sit = s.begin();
            int prev_val = *sit;
            sit++;
            for (; sit != s.end(); ++sit) {
                t_min = min(t_min, *sit - prev_val);
                prev_val = *sit;
            }

            ans.push_back(t_min);
        }
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,3,4,8 };
    vector<vector<int>> queries = { {0,1} ,{1,2},{2,3},{0,3} };

    vector<int> ans = sol.minDifference(nums, queries);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
