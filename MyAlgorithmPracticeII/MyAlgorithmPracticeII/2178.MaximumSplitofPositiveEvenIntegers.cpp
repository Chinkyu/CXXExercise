//  see solution  :  생각보다 간단함...
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
#include <functional>

using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long n) {
        if (n % 2) // odd
            return {};

        vector<long long> ans;
        long long i = 2;
        long long crSum = 0;

        while ((crSum + i) <= n)
        {
            ans.push_back(i);
            crSum += i;
            i += 2;
        }

        // add remaining difference to the last value in answer list
        int sz = ans.size();
        ans[sz - 1] += (n - crSum);
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 2, 10, 3, 2 };

    cout << sol.minimumRemoval(nums);

    cin >> c;
}