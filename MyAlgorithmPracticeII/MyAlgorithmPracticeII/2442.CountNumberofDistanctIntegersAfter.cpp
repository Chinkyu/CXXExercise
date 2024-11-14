//  easy 
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
    int countDistinctIntegers(vector<int>& nums) {

        unordered_map<int, int> m;

        for (auto& it : nums) {
            m[it]++;

            int rv = 0;
            int cv = it;
            // reverse
            while (cv > 0) {
                int dig = cv % 10;
                rv *= 10;
                rv += dig;
                cv /= 10;
            }

            m[rv]++;
        }

        return m.size();
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,13,10,12,31 };

    cout << sol.countDistinctIntegers(nums);

    cin >> c;
}