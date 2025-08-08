// ok :  
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <cmath>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end(), std::greater<int>());

        int h = maximumHeight[0];
        long long ans = h;
        for (int i = 1; i < maximumHeight.size(); ++i) {
            h--;
            if (maximumHeight[i] < h) {
                h = maximumHeight[i];
            }

            if (h <= 0) return -1;
            ans += h;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> nums = { 2,2, 1 };

    cout << sol.maximumTotalSum(nums);

    std::cin >> c;
}