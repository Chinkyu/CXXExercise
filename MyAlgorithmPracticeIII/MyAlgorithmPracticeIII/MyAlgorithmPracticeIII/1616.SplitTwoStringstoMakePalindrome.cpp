// see answer. 
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
#include <chrono>
#include <iterator>

using namespace std;

class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        while (i < j && s[i] == s[j])
            ++i, --j;
        return i >= j;
    }
    bool check(string& a, string& b) {
        int i = 0, j = a.size() - 1;
        while (i < j && a[i] == b[j])
            ++i, --j;
        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,0,-1,0,-2,2 };

    vector<vector<int>> ans = sol.fourSum(nums, 0);

    for (auto& it : ans) {
        cout << it[0] << "," << it[1] << "," << it[2] << "." << it[3];
    }


    cin >> c;
}
