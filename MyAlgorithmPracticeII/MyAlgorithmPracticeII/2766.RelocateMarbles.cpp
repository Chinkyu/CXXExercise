// ok. : 

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
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int, int> m;

        for (auto it : nums) {
            m[it]++;
        }

        for (int i = 0; i < moveFrom.size(); ++i) {
            if (moveFrom[i] == moveTo[i]) continue;
            if (m.find(moveTo[i]) != m.end()) {
                m[moveTo[i]] += m[moveFrom[i]];
                m.erase(moveFrom[i]);
            }
            else {
                m[moveTo[i]] = m[moveFrom[i]];
                m.erase(moveFrom[i]);
            }
        }

        vector<int> ans;
        for (auto it: m) {
            if (it.second == 0) continue;
            ans.push_back(it.first);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    //vector<int> nums = { 1,6,7,8 };
    //vector<int> moveFrom = { 1,7,2 }, moveTo = { 2,9,5 };

    vector<int> nums = { 3,4 };
    vector<int> moveFrom = { 4,3,1,2,2,3,2,4,1 }, moveTo = { 3,1,2,2,3,2,4,1,1 };

    vector<int> ans = sol.relocateMarbles(nums, moveFrom, moveTo);

    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}