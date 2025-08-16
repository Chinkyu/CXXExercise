// see anser - dp
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
    int countNumbersWithUniqueDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 9, cal = 9;
            int j = i;
            while (--j) {
                cnt *= cal;
                cal--;
            }
            ans += cnt;
        }
        return ans + 1;
    }
};

int main() {
    char c;
    Solution sol;
    string s = "001101";

    cout << sol.countNumbersWithUniqueDigits(3);

    std::cin >> c;
}