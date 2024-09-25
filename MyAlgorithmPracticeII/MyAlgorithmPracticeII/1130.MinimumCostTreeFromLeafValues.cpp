// 답봤음 : dynamic programming... 
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
    int solve(map<pair<int, int>, int>& mp, int l, int r, vector<vector<int>>& v) {
        if (l == r)return 0;
        int ans = INT_MAX;
        if (v[l][r] != -1)return v[l][r];
        for (int i = l; i < r; i++) {
            ans = min(ans, mp[{l, i}] * mp[{i + 1, r}] + solve(mp, l, i, v) + solve(mp, i + 1, r, v));
        }
        return v[l][r] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> mp;
        int i, j, n = arr.size();
        for (i = 0; i < n; i++) {
            mp[{i, i}] = arr[i];
            for (j = i + 1; j < n; j++) {
                mp[{i, j}] = max(mp[{i, j - 1}], arr[j]);
            }
        }
        vector<vector<int>> v(n, vector<int>(n, -1));
        // for(auto &i: mp)cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
        return solve(mp, 0, n - 1, v);
    }
};

// 이렇게 안풀림...
class _Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> sarr = arr;
        vector<int> darr;

        int ans = 0;
        do {
            darr.clear();
            for (int i = 0; i + 1 < sarr.size(); i += 2) {
                int m = sarr[i] * sarr[i + 1];
                int large = (sarr[i] > sarr[i + 1]) ? sarr[i] : sarr[i + 1];
                darr.push_back(large);
                ans += m;
            }

            if (sarr.size() % 2 == 1) {
                darr.push_back(*sarr.rbegin());
            }
            sarr = darr;
        } while (darr.size() != 1);

        int lsum = ans;

        sarr = arr;
        reverse(sarr.begin(), sarr.end());
        ans = 0;
        do {
            darr.clear();
            for (int i = 0; i + 1 < sarr.size(); i += 2) {
                int m = sarr[i] * sarr[i + 1];
                int large = (sarr[i] > sarr[i + 1]) ? sarr[i] : sarr[i + 1];
                darr.push_back(large);
                ans += m;
            }

            if (sarr.size() % 2 == 1) {
                darr.push_back(*sarr.rbegin());
            }
            sarr = darr;
        } while (darr.size() != 1);

        int rsum = ans;

        return (lsum < rsum) ? lsum : rsum;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> arr = { 6, 2,4};

    cout << sol.mctFromLeafValues(arr);
    cin >> c;
}