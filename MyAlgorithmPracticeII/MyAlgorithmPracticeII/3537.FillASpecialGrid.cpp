// ok : just use recursive sith stck....   if we increase size.. it will stack overflow
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
    vector<vector<int>> specialGrid(int n) {

        if (n == 0) {
            return { {0} };
        }

        if (n == 1) {
            return vector<vector<int>> {{ 3, 0}, { 2, 1 }};
        }
        int l = pow(2, n);
        vector<vector<int>> ans(l, vector<int>(l, 0));

        vector<vector<int>> pre = specialGrid(n - 1);
        int lp = pre.size();
        int size = lp * lp;

        // lt
        for (int i = 0; i < lp; ++i) {
            for (int j = 0; j < lp; ++j) {
                ans[i][j + lp] = pre[i][j];             // right top
                ans[i + lp][j + lp] = pre[i][j] + size; // right bottom
                ans[i + lp][j] = pre[i][j] + size * 2;       // left bottom
                ans[i][j] = pre[i][j] + size * 3;       // left top
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    char c;

    auto ans = sol.specialGrid(2);


    cin >> c;
}
