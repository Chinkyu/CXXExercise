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
    char findKthBit(int n, int k) {

        string s = "0";

        for (int i = 2; i <= n; ++i) {
            string rs = s;
            for (int j = 0; j < rs.size(); ++j) rs[j] = (rs[j] == '0') ? '1' : '0';
            reverse(rs.begin(), rs.end());
            s = s + "1" + rs;
        }

        return s[k-1];
    }
};

int main() {
    char c;
    Solution sol;

    cout << sol.findKthBit(4, 11);

    cin >> c;
}