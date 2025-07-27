// ok : sqrt and find from one step down 

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
#include <cmath>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:
    vector<int> closestDivisors(int num) {
        double s = sqrt(num + 1);
        vector<int> ans;

        int df = INT_MAX;
        int n = num + 1;
        int d1 = sqrt(n);
        while (d1 * (n / d1) != n) d1--;
        if (df > abs(d1 - (n / d1))) {
            ans = { d1, n / d1 };
            df = abs(d1 - (n / d1));
        }

        n = num + 2;
        d1 = sqrt(n);
        while (d1 * (n / d1) != n) d1--;
        if (df > abs(d1 - (n / d1))) {
            ans = { d1, n / d1 };
        }
        
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    //string num1 = "9", num2 = "99";

    vector<int> ans = sol.closestDivisors(999);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}