// Easy
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>A
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
    vector<string> ans;

    vector<string> addOperators(string s, int target) {
        helper(s, target, 0, "", 0, 0);
        return ans;
    }
    void helper(string s, int target, int i, const string& path, long eval, long residual) {
        // bc
        if (i == s.length()) {
            if (eval == target) {
                ans.push_back(path);
                return;
            }
        }
        string currStr;
        long num = 0;
        // backtracking loop
        for (int j = i; j < s.length(); j++) {
            // handle 0
            if (j > i && s[i] == '0') return;
            currStr += s[j];
            num = num * 10 + s[j] - '0';
            if (i == 0) {
                helper(s, target, j + 1, path + currStr, num, num);
            }
            else {
                helper(s, target, j + 1, path + "+" + currStr, eval + num, num);
                helper(s, target, j + 1, path + "-" + currStr, eval - num, -num);
                helper(s, target, j + 1, path + "*" + currStr, eval - residual + residual * num, residual * num);


            }
        }
    }
};

int main() {
    Solution sol;
    char c;

    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };

    vector<int> ans = sol.maxSlidingWindow(nums, 3);


    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
