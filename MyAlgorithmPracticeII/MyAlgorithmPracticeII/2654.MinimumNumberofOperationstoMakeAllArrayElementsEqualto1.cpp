// see answer
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
Q3. How do you get the minimum number of operations required to make any of the elements as 1?
A3. given the constraints, for any element I we can traverse through all elements (say iterator j) 
from i+1 to n and take their gcd. As soon as the gcd becomes 1 we can conclude that taking gcd in the 
reverse fashion (from nums[j] to nums[i]) would make nums[i] equal to 1.
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int c = count(nums.begin(), nums.end(), 1);     // if there is at least 1. then it's easy!
        if (c != 0)    return n - c;
        int res = 1e7;        // just a dummy value
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = __gcd(g, nums[j]);
                if (g == 1) {
                    res = min(res, j - i + (n - 1)); // number of operations to make this element 1+ number of non ones (i.e. n-1) .
                    break;
                }
            }
        }
        return res == 1e7 ? -1 : res;
    }
};

int main() {
    Solution sol;
    char c;
    vector<int> tasks = { 2,2,3,3,2,4,4,4,4,4 };

    cout << sol.minimumRounds(tasks);

    cin >> c;
}
