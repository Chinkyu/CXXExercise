// see answer : solve wit math  n(n+1)/2
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
    int magicalString(int n) {
        if (n < 4) return 1;
        vector<int> arr(n + 2, 0);
        arr[2] = 2;
        int res = 1;
        for (int idx = 2, curr = 1, pos = 3; pos < n; ++idx) {
            for (int j = 0; j < arr[idx] && pos < n; ++j, ++pos) {
                arr[pos] = curr;
                if (curr == 1) ++res;
            }
            curr ^= 3;
        }
        return res;
    }
};
int main() {
    char c;
    Solution sol;

    cout << sol.minimumPossibleSum(39636, 49035);


    cin >> c;
}