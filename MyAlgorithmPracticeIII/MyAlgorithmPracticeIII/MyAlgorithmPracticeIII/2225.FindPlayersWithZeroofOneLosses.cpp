// ok. 
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

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> win, loose, oneloose;

        for (auto& it : matches) {
            // all win 
            win[it[0]]++;

            // all win 
            loose[it[1]]++;
        }

        vector<vector<int>> ans(2, vector<int>());
        // all win 
        for (auto& it : win) {
            if (loose.find(it.first) == loose.end()) {
                ans[0].push_back(it.first);
            }
        }
        sort(ans[0].begin(), ans[0].end());


        // one loose
        for (auto& it : loose) {
            if (it.second == 1) {
                ans[1].push_back(it.first);
            }
        }
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums1 = { 18,11,24,9,10,11,7,29,16 };
    vector<int> nums2 = { 28,26,27,4,2,19,23,1,2 };

    vector<long long> ans = sol.findMaxSum(nums1, nums2, 1);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
