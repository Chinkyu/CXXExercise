// 잘 이해 안감... 수학식으로도 이해 안감. 
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
    string baseNeg2(int n) {
        string res = "";
        while (n) {
            res = to_string(n & 1) + res;
            n = -(n >> 1);
        }
        return res == "" ? "0" : res;
    }
};



int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1, 10, 2, 9 };


    cout << sol.minMoves2(nums);

    cin >> c;
}