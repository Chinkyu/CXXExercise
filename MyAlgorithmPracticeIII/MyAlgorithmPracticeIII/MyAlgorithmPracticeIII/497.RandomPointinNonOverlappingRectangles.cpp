// Look logic good : let's skip..
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
    vector<long long> nums = { 0 };
    vector<vector<int>> rec;


    Solution(vector<vector<int>>& rects) {
        int l = rects.size();

        long long pre = 0;
        rec = rects;

        for (int i = 0; i < l; ++i) {
            long long dim = abs(rects[i][2] - rects[i][0]) * abs(rects[i][3] - rects[i][1]);

            nums.push_back(dim + pre);
            pre = dim + pre;
        }
    }

    vector<int> pick() {
        long long t_max = nums.back();
        vector<int> ans;

        // 1. Obtain a random seed from the hardware
        std::random_device rd;

        // 2. Standard mersenne_twister_engine seeded with rd()
        std::mt19937 gen(rd());

        // 3. Define the range [inclusive, inclusive]
        std::uniform_int_distribution<long long> distrib(0, t_max - 1);

        // 4. Generate the random number
        long long random_value = distrib(gen);
        

        // Find the first element strictly greater than target
        auto it = std::upper_bound(nums.begin(), nums.end(), random_value);

        // If it points to the beginning, no element is <= target
        if (it != nums.begin()) {
            // Step back to get the element less than or equal to target
            --it;

            int index = std::distance(nums.begin(), it);
            int displacement = random_value - *it;

            long long w = rec[index][2] - rec[index][0];
            int iy = displacement / w;
            int ix = displacement % w;

            ans = { rec[index][0] + ix, rec[index][1] + iy };
            return ans;
        }
        else {
            std::cout << "Target is out of lower bounds.\n";
        }

        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

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
