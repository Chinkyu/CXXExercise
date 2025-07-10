// ok : easy
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

class Solution {
public:
    unordered_map<char, string> m = {
        { '2', "abc"},
        { '3', "def"},
        { '4', "ghi"},
        { '5', "jkl"},
        { '6', "mno"},
        { '7', "pqrs"},
        { '8', "tuv"},
        { '9', "wxyz"},
    };

    void traverse(string &digits, int idx, string s, vector<string>& ans) {

        if (idx == digits.size()) {
            ans.push_back(s);
            return;
        }

        for (auto& it : m[digits[idx]]) {
            traverse(digits, idx + 1, s + it, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s = "";

        if (digits == "") return ans;

        traverse(digits, 0, s, ans);

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string digits = "23";

    vector<string> ans =  sol.letterCombinations(digits);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}