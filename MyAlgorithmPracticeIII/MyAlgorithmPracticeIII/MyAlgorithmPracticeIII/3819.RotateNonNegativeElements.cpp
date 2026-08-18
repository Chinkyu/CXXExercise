// ok. 
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
    vector<int> rotateElements(vector<int>& nums, int k) {
        int l = nums.size();
        vector<int> np;
        vector<int> ans = nums;

        for (int i = 0; i < l; ++i) {
            if (nums[i] >= 0) {
                np.push_back(nums[i]);
            }
        }

        int npl = np.size();

        if (npl == 0) {  // no non negative number
            return nums;
        }

        k %= npl;
        rotate(np.begin(), np.begin() + k, np.end());

        for(int i = 0, j = 0; i < l; ++i) {
            if (ans[i] >= 0) {
                ans[i] = np[j++];
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
