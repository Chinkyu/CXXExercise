// ok.... just need care about zero
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
    vector<int> productExceptSelf(vector<int>& nums) {
        long long all = 1;
        int l = nums.size();

        int zero_count = 0;
        int zero_idx = -1;

        for (int i = 0; i < l; ++i) {
            if (nums[i] != 0) {
                all *= nums[i];
            }
            else {
                zero_count++;
                zero_idx = i;
            }
        }

        vector<int> ans;

        if (zero_count >= 2) {
            ans = vector<int>(l, 0);
            return ans;
        }
        else if (zero_count == 1) {
            ans = vector<int>(l, 0);
            ans[zero_idx] = all;
            return ans;
        }

        for (int i = 0; i < l; ++i) {
            ans.push_back(all / nums[i]);
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
