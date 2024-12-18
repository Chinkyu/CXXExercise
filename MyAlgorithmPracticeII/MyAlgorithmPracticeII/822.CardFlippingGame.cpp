// 답보고 했음... 
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
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        vector<int> count(2001, 0);
        int n = fronts.size();

        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) {
                count[fronts[i]]++;
            }
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (count[fronts[i]] == 0) {
                res = std::min(res, fronts[i]);
            }
            if (count[backs[i]] == 0) {
                res = std::min(res, backs[i]);
            }
        }

        return (res == INT_MAX) ? 0 : res;
    }
}

int main() {
    char c;
    Solution sol;
    vector<vector<int>> points = { {3, 3}, {5, -1}, {-2, 4} };

    vector<vector<int>> ans = sol.kClosest(points, 2);

    for (auto& it : ans) {
        cout << it[0] << " " << it[1] << endl;
    }

    cin >> c;
}