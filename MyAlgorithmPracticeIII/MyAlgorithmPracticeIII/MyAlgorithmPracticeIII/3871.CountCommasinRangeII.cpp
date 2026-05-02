// see answer 
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
    long long countCommas(long long n) {
        long long res = 0, p;
        for (p = 1000; p <= n; p *= 1000)
            res += n - p + 1;
        return res;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 0,3,7,2,5,8,4,6,0,1 };

    cout << sol.longestConsecutive(nums);

    cin >> c;
}
