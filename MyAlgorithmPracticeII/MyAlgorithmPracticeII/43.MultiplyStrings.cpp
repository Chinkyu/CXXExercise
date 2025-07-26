// ok : debugging 

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
    string adder(string num1, string num2) {
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        string ans;

        int r = 0;
        for (int i = 0; i < num2.size() || i < num1.size(); ++i) {
            int n1 = (i < num1.size()) ? num1[i] - '0' : 0;
            int n2 = (i < num2.size()) ? num2[i] - '0' : 0;

            r = n1 + n2 + r;

            ans.push_back(r % 10 + '0');
            r = r / 10;
        }
        if (r > 0) ans.push_back(r + '0');

        std::reverse(ans.begin(), ans.end());
        return ans;
    }

    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0") return "0";

        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        string ans;

        int r = 0;
        for (int i = 0; i < num1.size(); ++i) {
            string la(i, '0');
            r = 0;
            for (int j = 0; j < num2.size(); ++j) {
                int n1 = (i < num1.size()) ? num1[i] - '0' : 1;
                int n2 = (j < num2.size()) ? num2[j] - '0' : 1;


                r = n1 * n2 + r;

                la.push_back(r % 10 + '0');
                r = r / 10;
            }
            if (r > 0) la.push_back(r + '0');

            reverse(la.begin(), la.end());
            ans = adder(ans, la);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string num1 = "9", num2 = "99";

    cout << sol.multiply(num1, num2);

    cin >> c;
}