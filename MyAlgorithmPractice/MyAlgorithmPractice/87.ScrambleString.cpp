﻿// 답봤음... : recursive dynamic program
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
private:
    int dp[40][40][40];
    bool solve(string& s1, string& s2, int l1, int l2, int len) {
        if (len == 0) {
            return dp[l1][l2][len] = true;
        }
        if (dp[l1][l2][len] != -1) {
            return dp[l1][l2][len];
        }
        for (int i = l1, j = l2; i <= len + l1; i++, j++) {
            if (i == l1 + len) {
                return dp[l1][l2][len] = true;
            }
            if (s1[i] != s2[j]) {
                break;
            }
        }
        vector<int>v(26, 0);
        for (int i = l1, j = l2; i < len + l1; i++, j++) {
            v[s1[i] - 'a']++;
            v[s2[j] - 'a']--;
        }
        for (auto x : v) {
            if (x) return dp[l1][l2][len] = false;
        }
        for (int i = 1; i < len; i++) {
            if (solve(s1, s2, l1, l2, i) && solve(s1, s2, l1 + i, l2 + i, len - i)) {
                return dp[l1][l2][len] = true;
            }

            if (solve(s1, s2, l1 + i, l2, len - i) && solve(s1, s2, l1, l2 + (len - i), i)) {
                return dp[l1][l2][len] = true;
            }
        }
        return dp[l1][l2][len] = false;
    }
public:
    bool isScramble(string s1, string s2) {
        memset(dp, -1, sizeof dp);
        return solve(s1, s2, 0, 0, s1.size());
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> heights = { 2,1,5,6,2,3 };

    cout << sol.largestRectangleArea(heights);

    cin >> c;
}