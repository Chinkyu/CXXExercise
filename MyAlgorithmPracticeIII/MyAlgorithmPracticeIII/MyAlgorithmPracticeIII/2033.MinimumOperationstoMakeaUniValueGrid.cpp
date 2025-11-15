// ok : some try and error 
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
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;

        for (auto& it : grid) {
            for (auto& jt : it) {
                v.push_back(jt);
            }
        }

        int l = v.size();
        if (l == 1) return 0;


        sort(v.begin(), v.end());

        int distl = 0, distr = 0;

        // always even number
        for (int i = 0; i < l; ++i) {
            int dl = abs(v[i] - v[l / 2]);
            if (dl% x != 0) distl = -1;
            if (distl != -1) distl += dl;

            if (l / 2 + 1 < l) {
                int dr = abs(v[i] - v[l / 2 + 1]);
                if (dr % x != 0) distr = -1;
                if (distr != -1) distr += dr;
            }
            else {
                distr = -1;
            }
        }

        if (distl != -1 && distr != -1) {
            int distm = min(distl, distr);
            return distm / x;

        } else if (distl == -1 && distr == -1) {
            return -1;
        } else if (distl != -1) {
            return distl / x;
        }
        else {
            return distr / x;
        }

    }
};

int main() {
    char c;
    Solution sol;
    //vector<int> asteroids = {5, 10, -5};
    vector<int> starPos = { 1, 0 };
    vector<int> homePos = { 2, 3 };
    vector<int> rowCosts = { 5, 4, 3 };
    vector<int> colCosts = { 8, 2, 6, 7 };

    cout << sol.minCost(starPos, homePos, rowCosts, colCosts);


    //cout << "Test  application";

    cin >> c;
}
