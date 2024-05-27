//  its ok
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

    void get(vector<vector<int>>& grid, vector<int>& base, int lr, int lc, vector<int> &out) {

        int r = base[0], c = base[1];

        // self
        out.push_back(grid[r][c]);

        // right
        for (int i = 1; i < lc; ++i) {
            c++;
            out.push_back(grid[r][c]);
        }

        // down
        for (int i = 1; i < lr; ++i) {
            r++;
            out.push_back(grid[r][c]);
        }

        // left
        for (int i = 1; i < lc; ++i) {
            c--;
            out.push_back(grid[r][c]);
        }

        // up
        for (int i = 1; i < lr - 1; ++i) {
            r--;
            out.push_back(grid[r][c]);
        }
    }

    void set(vector<vector<int>>& grid, vector<int>& base, int lr, int lc, vector<int> &in) {
        int idx = 0;
        int r = base[0], c = base[1];

        // self
        grid[r][c] = in[idx++];

        // right
        for (int i = 1; i < lc; ++i) {
            c++;
            grid[r][c] = in[idx++];
        }

        // down
        for (int i = 1; i < lr; ++i) {
            r++;
            grid[r][c] = in[idx++];
        }

        // left
        for (int i = 1; i < lc; ++i) {
            c--;
            grid[r][c] = in[idx++];
        }

        // up
        for (int i = 1; i < lr - 1; ++i) {
            r--;
            grid[r][c] = in[idx++];
        }
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int lr = grid.size();
        int lc = grid[0].size();
        vector<vector<int>> ans(lr, vector<int>(lc, 0));


        vector<int> base = { 0, 0 };
        while (lr > 0 && lc > 0) {
            vector<int> num;
            get(grid, base, lr, lc, num);

            // shifting k
            int shifting = k % num.size();
            for (int i = 0; i < shifting; ++i) {
                num.push_back(num[0]);
                num.erase(num.begin());
            }

            set(ans, base, lr, lc, num);
        
            base[0]++;
            base[1]++;

            lr -= 2;
            lc -= 2;
        }

        return ans;
    }

};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> grid =
        {{3970, 1906, 3608, 298, 3072, 3546, 1502, 773, 4388, 3115, 747, 3937}, {2822, 304, 4179, 1780, 1709, 1058, 3645, 681, 2910, 2513, 4357, 1038}, {4471, 2443, 218, 550, 2766, 4780, 1997, 1672, 4095, 161, 4645, 3838}, {2035, 2350, 3653, 4127, 3208, 4717, 4347, 3452, 1601, 3725, 3060, 2270}, {188, 2278, 81, 3454, 3204, 1897, 2862, 4381, 3704, 2587, 743, 3832}, {996, 4499, 66, 2742, 1761, 1189, 608, 509, 2344, 3271, 3076, 108}, {3274, 2042, 2157, 3226, 2938, 3766, 2610, 4510, 219, 1276, 3712, 4143}, {744, 234, 2159, 4478, 4161, 4549, 4214, 4272, 701, 4376, 3110, 4896}, {4431, 1011, 757, 2690, 83, 3546, 946, 1122, 2216, 3944, 2715, 2842}, {898, 4087, 703, 4153, 3297, 2968, 3268, 4717, 1922, 2527, 3139, 1516}, {1086, 1090, 302, 1273, 2292, 234, 3268, 2284, 4203, 3838, 2227, 3651}, {2055, 4406, 2278, 3351, 3217, 2506, 4525, 233, 3829, 63, 4470, 3170}, {3797, 3276, 1755, 1727, 1131, 4108, 3633, 1835, 1345, 1293, 2778, 2805}, {1215, 84, 282, 2721, 2360, 2321, 1435, 2617, 1202, 2876, 3420, 3034}};
    //{{10, 1, 4, 8}, {6, 6, 3, 10}, {7, 4, 7, 10}, {1, 10, 6, 1}, {2, 1, 1, 10}, {3, 8, 9, 2}, {7, 1, 10, 10}, {7, 1, 4, 9}, {2, 2, 4, 2}, {10, 7, 5, 10}};
    //{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };

    vector<vector<int>> ans =  sol.rotateGrid(grid, 0);

    for (auto it : ans) {
        for (auto jt : it) {
            cout << jt << " ";
        }
        cout << endl;
    }

    cin >> c;
}