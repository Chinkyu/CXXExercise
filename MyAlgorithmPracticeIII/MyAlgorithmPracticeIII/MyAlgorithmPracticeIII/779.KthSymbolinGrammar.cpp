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
    int kthGrammar(int n, int k) {
        // Initialize a flag to track if the values of k and first element are the same.
        bool areValuesSame = true;

        // Calculate the total number of elements in the nth row, which is 2^(n-1).
        n = pow(2, n - 1);

        // Continue until we reach the first row.
        while (n != 1) {
            // Halve the number of elements in the row.
            n /= 2;

            // If k is in the second half of the row, adjust k and toggle the flag.
            if (k > n) {
                k -= n;
                areValuesSame = !areValuesSame;
            }
        }

        // Return 0 if the flag indicates that the values are the same; otherwise, return 1.
        return ((areValuesSame) ? 0 : 1);
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> numbers = { 2, 7, 11, 15 };

    vector<int> ans = sol.twoSum(numbers, 9);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
