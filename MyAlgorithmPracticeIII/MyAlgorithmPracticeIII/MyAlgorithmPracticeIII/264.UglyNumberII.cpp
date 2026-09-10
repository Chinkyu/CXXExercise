// see
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
    int nthUglyNumber(int n) {
        set<long> uglyNumbersSet;  // Set to store potential ugly numbers
        uglyNumbersSet.insert(1);  // Start with 1, the first ugly number

        long currentUgly = 1;
        for (int i = 0; i < n; i++) {
            currentUgly =
                *uglyNumbersSet
                .begin();  // Get the smallest number from the set
            uglyNumbersSet.erase(
                uglyNumbersSet.begin());  // Remove it from the set

            // Insert the next potential ugly numbers
            uglyNumbersSet.insert(currentUgly * 2);
            uglyNumbersSet.insert(currentUgly * 3);
            uglyNumbersSet.insert(currentUgly * 5);
        }

        return static_cast<int>(currentUgly);  // Return the nth ugly number
    }
};

int main() {
    char c;
    Solution sol;
    //string s = "2[abc]3[cd]ef3[cd]";
    //string s = "2[abc]zzzz";
    string s = "3[a2[c]]";

    //cout << sol.exchange(s, 5);
    cout << sol.decodeString(s);


    //cout << "Test  application";

    cin >> c;
}
