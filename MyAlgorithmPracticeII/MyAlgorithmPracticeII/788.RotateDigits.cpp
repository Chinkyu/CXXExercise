// easy : brute force ..
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
    int rotatedDigits(int n) {

        int ans = 0;

        for (int i = 1; i <= n; ++i) {
            string s = to_string(i);
            bool isFound = false;
            bool is2569 = false;
            for (int j = 0; j < s.size(); ++j) {
                if (s[j] == '3' || s[j] == '4' || s[j] == '7') {
                    isFound = true;
                    break;
                }
                if (s[j] == '2' || s[j] == '5' || s[j] == '6' || s[j] == '9') {
                    is2569 = true;
                }
            }

            if (isFound == true) continue;
            if (is2569 == true) ans++;

        }

        return ans;
    }
};


int main() {
    char c;
    Solution sol;
    cout << sol.rotatedDigits(10);

    cin >> c;
}