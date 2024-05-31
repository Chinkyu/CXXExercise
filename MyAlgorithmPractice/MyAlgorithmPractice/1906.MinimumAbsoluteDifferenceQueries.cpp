// ¥‰∫√¿Ω : 
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
    vector<int> minDifference(vector<int>& A, vector<vector<int>>& Q) {
        vector<int> ans(Q.size());
        int prefix[100001][101] = {}, cnt[101] = {}, N = A.size(), M = Q.size();
        for (int i = 0; i < N; ++i) {
            cnt[A[i]]++;
            for (int j = 1; j < 101; ++j) prefix[i + 1][j] = cnt[j];
        }
        for (int i = 0; i < M; ++i) {
            int L = Q[i][0], R = Q[i][1], cnt[101] = {};
            for (int j = 0; j < 101; ++j) cnt[j] = prefix[R + 1][j] - prefix[L][j];
            int prev = -1, minAbs = INT_MAX;
            for (int j = 1; j < 101; ++j) {
                if (cnt[j] == 0) continue;
                if (prev != -1 && j - prev < minAbs) minAbs = j - prev;
                prev = j;
            }
            ans[i] = minAbs == INT_MAX ? -1 : minAbs;
        }
        return ans;
    }
};

// timeout 
class _Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;

        for (auto& it : queries) {
            map<int, int> m;

            for (int i = it[0]; i <= it[1]; ++i) {
                m[nums[i]]++;
            }

            if (m.size() <= 1) {
                ans.push_back(-1);
                continue;
            }

            int prev =  -300; // max
            int min_gap = INT_MAX;
            for (auto& it : m) {
                min_gap = min(min_gap, abs(it.first - prev));
                prev = it.first;
            }

            if (min_gap == INT_MAX) 
                ans.push_back(-1);
            else 
                ans.push_back(min_gap);
        }

        return ans;

    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 4,5,2,2,7,10 };
    vector<vector<int>> queries = {{2, 3}, {0, 2}, {0, 5}, {3, 5}};

    vector<int> ans = sol.minDifference(nums, queries);

    for (auto& it : ans) {
        cout << it << " ";
    }
    cin >> c;
}