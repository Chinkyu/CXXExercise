// ok : a - b  -> sort  and half to a half to b
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
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int l = costs.size();
        vector<vector<int>> v;

        for (int i = 0; i < costs.size(); ++i) {
            v.push_back({ costs[i][0] - costs[i][1], i });
        }

        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (i < l / 2) {
                ans += costs[v[i][1]][0]; // a city
            }
            else {
                ans += costs[v[i][1]][1];  // b city
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};

    cout << sol.twoCitySchedCost(costs);

    cin >> c;
}
