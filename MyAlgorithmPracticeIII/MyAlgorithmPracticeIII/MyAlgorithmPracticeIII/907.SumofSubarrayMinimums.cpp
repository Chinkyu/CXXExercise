//   : 
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
#include <bit>

using namespace std;


// mono stack 
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<vector<int>> stack;
        vector<int> res(arr.size(), 0);

        for (int i = 0; i < arr.size(); i++) {
            // use ">=" to deal with duplicate elements
            while (!stack.empty() && stack.top()[0] >= arr[i]) {
                stack.pop();
            }

            int j = stack.empty() ? -1 : stack.top()[1];
            res[i] = stack.empty() ? arr[i] * (i + 1) : res[j] + arr[i] * (i - j);
            stack.push({ arr[i], i });
        }

        const long MOD = static_cast<long>(1e9 + 7);
        long ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            ans = (ans + static_cast<long>(res[i])) % MOD;
        }
        return static_cast<int>(ans);
    }
};

// timeout 
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int l = arr.size();

        int ans = 0;
        for (int i = 0; i < l; ++i) {
            for (int j = i; j < l; ++j) {
                int m = *min_element(arr.begin() + i, arr.begin() + j + 1);
                ans += m;
                ans %= 1000000007;
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 3,1,2,4 };

    cout << sol.sumSubarrayMins(nums);

    cin >> c;
}

