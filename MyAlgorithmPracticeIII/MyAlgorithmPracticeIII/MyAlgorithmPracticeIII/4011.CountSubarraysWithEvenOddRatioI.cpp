// brute force : barely passed 
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
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int l = nums.size();
        vector<vector<int>> c(l + 1, vector<int>(2, 0));

        for (int i = 0; i < l; ++i) {
            if (nums[i] % 2 == 0) {
                c[i + 1][0] = c[i][0] + 1;
                c[i + 1][1] = c[i][1];
            }
            else {
                c[i + 1][0] = c[i][0];
                c[i + 1][1] = c[i][1] + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l + 1; ++j) {
                int ev = c[j][0] - c[i][0];
                int od = c[j][1] - c[i][1];

                if (od > 0 && (ev / (double)od <= a / (double)b)) {
                    ans++;
                }

            }
        }

        return ans;
    }
};

int main() {
    char c;
    //vector<vector<int>> n = { { -2, -2, 1, 1},{2, 2, 4, 6} };
    vector<vector<int>> n = { { 1, 1, 5, 5} };


    Solution sol(n);

    for (int i = 0; i < 5; ++i) {
        vector<int> ans = sol.pick();
        cout << ans[0] << " " << ans[1] << endl;
    }

    cin >> c;
}
