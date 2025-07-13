// see answer : same with 198 house robber
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
#include <iostream>

using namespace std;

// 아... 쭉 펼쳐서 없는거는 0 넣고 하면 되는구나..!!!
int deleteAndEarn(vector<int>& nums) {
    int n = 10001;

    //take the total sum by each number
    vector<int> sum(n, 0);
    vector<int> dp(n, 0);

    for (auto num : nums) {
        sum[num] += num;
    }

    dp[0] = 0;
    dp[1] = sum[1];
    //now apply the house robbing concept
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 2] + sum[i], dp[i - 1]);
    }

    return dp[n - 1];
}


// 연결이 끈어진경우는 문제가 생김... 연속구간으로 짤라서 나눠서 계산히야함...   잘 안됨 
class _Solution {
public:
    int deleteAndEarn_sub(vector<vector<int>>& v) {
        int l = v.size();

        if (l == 1) return v[0][1];
        vector<int> dp(l, 0);

        dp[0] = v[0][1];
        if (v[0][0] == v[1][0] - 1) {
            dp[1] = max(v[0][1], v[1][1]);
        }
        else {
            dp[1] = dp[0] + v[1][1];
        }

        for (int i = 2; i < l; ++i) {
            if (v[i-1][0] == v[i][0] - 1) {
                dp[i] = max(v[i-1][1], v[i][1] + dp[i - 2]);
            }
            else {
                dp[i] = dp[i - 1] + v[1][1];
            }
        }

        return dp[l - 1];

    }

    int deleteAndEarn(vector<int>& nums) {
        map<int, int> m;
        vector<vector<int>> v;

        for (auto& it : nums) {
            m[it] += it;
        }

        for (auto& it : m) {
            v.push_back({ it.first, it.second });
        }

        int l = v.size();
        if (l == 1) return v[0][1];

        int pre = -1;
        int ans = 0;
        vector<vector<int>> sub_v;
        for (int i = 0; i < v.size(); ++i) {
            if (pre != v[i][0] - 1) {
                if (sub_v.size() != 0) ans += deleteAndEarn_sub(sub_v);
                sub_v.clear();
                sub_v.push_back({ v[i][0], v[i][1] });
            }
            else {
                sub_v.push_back({ v[i][0], v[i][1] });
            }
            pre = v[i][0];
        }
        if (sub_v.size() != 0) ans += deleteAndEarn_sub(sub_v);

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 3, 1 }; // { 1, 1, 1, 2, 4, 5, 5, 5, 6 };

    cout << sol.deleteAndEarn(nums);

    cin >> c;
}