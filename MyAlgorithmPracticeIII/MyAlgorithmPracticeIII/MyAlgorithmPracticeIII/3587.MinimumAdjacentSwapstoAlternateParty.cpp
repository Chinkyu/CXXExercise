// see answer : I'm sick
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
    int minSwaps(std::vector<int>& nums) {
        std::vector<int> ones;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 1) {
                ones.push_back(i);
            }
        }

        int m = 2 * ones.size();

        auto countSwaps = [&](int start) {
            int swaps = 0;
            for (int i = 0; i < ones.size(); ++i) {
                swaps += std::abs(ones[i] - (start + 2 * i));
            }
            return swaps; };

        if (m == n) {
            return std::min(countSwaps(0), countSwaps(1));
        }
        if (m == n + 1) {
            return countSwaps(0);
        }
        if (m == n - 1) {
            return countSwaps(1);
        }
        return -1;
    }
};


int main() {
    char c;
    Solution sol;

    string croakOfFrogs = "croakcrook";

    cout << sol.minNumberOfFrogs(croakOfFrogs);

    cin >> c;
}
