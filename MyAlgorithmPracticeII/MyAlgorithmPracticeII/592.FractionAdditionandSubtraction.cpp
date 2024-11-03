//  ¥‰∫√¿Ω.. 
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
    string fractionAddition(string expression) {
        class Solution {
        public:
            string fractionAddition(string expression) {
                int numerator = 0, denominator = 1;
                int i = 0;
                int n = expression.size();

                while (i < n) {
                    int sign = 1;
                    if (expression[i] == '+' || expression[i] == '-') {
                        if (expression[i] == '-') sign = -1;
                        i++;
                    }

                    int num = 0;
                    while (i < n && isdigit(expression[i])) {
                        num = num * 10 + (expression[i] - '0');
                        i++;
                    }
                    num *= sign;
                    i++;
                    int den = 0;
                    while (i < n && isdigit(expression[i])) {
                        den = den * 10 + (expression[i] - '0');
                        i++;
                    }
                    numerator = numerator * den + num * denominator;
                    denominator *= den;

                    int gcdVal = gcd(abs(numerator), denominator);
                    numerator /= gcdVal;
                    denominator /= gcdVal;

                }
                return to_string(numerator) + '/' + to_string(denominator);

            }
        };

    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 0, 1, 2 }; // { 5, 4, 0, 3, 1, 6, 2 };
    cout << sol.arrayNesting(nums);

    cin >> c;
}