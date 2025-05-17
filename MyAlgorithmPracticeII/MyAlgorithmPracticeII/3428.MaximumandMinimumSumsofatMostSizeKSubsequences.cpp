// see answer : ???
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
    int minMaxSums(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int MOD = 1e9 + 7;
        vector<vector<int>> ncr(nums.size() + 1, vector<int>(k + 1, 0));

        ncr[0][0] = 1;
        for (int n = 1; n <= nums.size(); n++) {
            ncr[n][0] = 1;
            for (int r = 1; r <= k; r++)
                ncr[n][r] = (ncr[n - 1][r - 1] + ncr[n - 1][r]) % MOD;
        }

        for (int n = 0; n < nums.size(); n++) {
            int numberOfSubsequences = 0;
            for (int r = 0; r <= k - 1; r++)
                if (n >= r) numberOfSubsequences = (numberOfSubsequences + ncr[n][r]) % MOD;
            ans = (ans + (long long)(nums[n] + nums[nums.size() - n - 1]) * numberOfSubsequences) % MOD;
        }
        return ans;
    }
};

int main() {
    char c;
    Bitset sol(5);

    sol.fix(3);
    sol.fix(1);
    sol.flip();
    cout << sol.all() << endl;
    sol.unfix(0);
    sol.flip();
    cout << sol.one() << endl;
    sol.unfix(0);
    cout << sol.count() << endl;
    cout << sol.toString() << endl;

    cin >> c;
}