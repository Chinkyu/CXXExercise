// refer answer : ....   l + r > r + l  return true, else return false
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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

/*

    Convert all numbers to strings.
    Sort them using a custom comparator: for two strings a and b, if b+a > a+b, then b should come before a.
    Join the sorted array.
    Handle edge case: if the result is all zeroes (like ['0', '0']), return "0" instead of "00".

*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;

        for (auto& it : nums) {
            v.push_back(std::to_string(it));
        }

        sort(v.begin(), v.end(), [](string& l, string& r) {
            if (l + r > r + l) return true;
            return false;
            });

        string ans;
        for(auto &it : v) {
            ans += it;
        }

        if (ans[0] == '0') ans = "0";
        return ans;
    }
};


int main() {
    Solution sol;
    char c;
    //vector<int> nums = { 3, 30, 34, 6, 9 };
    vector<int> nums = { 3, 30, 34, 6, 9 };

    cout << sol.largestNumber(nums);

    cin >> c;
}
