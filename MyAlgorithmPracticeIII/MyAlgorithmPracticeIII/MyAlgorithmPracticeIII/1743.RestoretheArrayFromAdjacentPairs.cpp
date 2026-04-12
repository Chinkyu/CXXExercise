// ok : graph only have two edge at mose 
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
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int l = adjacentPairs.size();
        unordered_map<int, vector<int>> ad;

        vector<int> ans;

        for (int i = 0; i < l; ++i) {
            ad[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            ad[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }

        // find first one 
        for (auto& it : ad) {
            if (it.second.size() == 1) {
                ans.push_back(it.first);
                ans.push_back(it.second[0]);
                break;
            }
        }

        while (ans.size() < l + 1) {
            int last = ans[ans.size() - 1];
            int pre = ans[ans.size() - 2];

            for (auto it : ad[last]) {
                if (it == pre) continue;

                ans.push_back(it);
                break;
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> adjacentPairs = {{2, 1}, {3, 4}, {3, 2}};
    vector<int> ans = sol.restoreArray(adjacentPairs);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
