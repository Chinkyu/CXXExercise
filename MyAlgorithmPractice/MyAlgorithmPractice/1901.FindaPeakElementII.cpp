// easy
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

using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int lr = mat.size();
        int lc = mat[0].size();

        int r = 0, c = 0;
        int cur = mat[r][c];

        vector<int> ans = { 0, 0 };

        if (lc == 1 && lr == 1) return ans;

        do {
            vector<int> direct(4, 0);

            cur = mat[r][c];

            direct[0] = (c - 1 < 0)? -1 : mat[r][c - 1];  // l
            direct[1] = (r - 1 < 0)? -1 : mat[r - 1][c];  // u
            direct[2] = (lc <= c + 1) ? -1 : mat[r][c + 1];  // r
            direct[3] = (lr <= r + 1) ? -1 : mat[r + 1][c];  // d

            int max_idx = 0;
            int tmax = direct[0];
            for (int i = 1; i < 4; ++i) {
                if (direct[i] > tmax) {
                    tmax = direct[i];
                    max_idx = i;
                }
            }

            if (tmax < cur) {
                ans[0] = r;
                ans[1] = c;
                return ans;
            }
            else {
                switch (max_idx) {
                case 0: c = c - 1;
                    break;
                case 1: r = r - 1;
                    break;
                case 2: c = c + 1;
                    break;
                case 3: r = r + 1;
                    break;
                }
            }


        } while (true);


        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> mat = { {67} }; 
    //{ { 10, 20, 15 }, { 21, 30, 14 }, { 7, 16, 32 } };

    vector<int> ans = sol.findPeakGrid(mat);

    cout << ans[0] << ", " << ans[1];

    cin >> c;
}