// Really easy: divide  3
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
#include <random>
#include <chrono>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long d3 = num / 3; 

        vector<long long> ans;
        if (d3 * 3 == num) {
            ans = { d3 - 1, d3, d3 + 1 };
        }

        if (d3 * 3 - 3 == num) {
            ans = { d3 - 2, d3 - 1, d3 };
        }

        if (d3 * 3 + 3 == num) {
            ans = { d3 , d3 + 1, d3 + 2 };
        }

        return ans;

    }
};

int main() {
    char c;
    Solution sol;

    vector<int> arr = { 1, 3, 5 };

    cout << sol.numOfSubarrays(arr);

    cin >> c;
}
