// 답봤음 : 문제 이해 안감... - skip
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
    int flip(int n) {
        // given integer abc returns intger cba by going to a temporary string
        auto str = to_string(n);
        std::reverse(str.begin(), str.end());
        return atoi(str.c_str());
    }

    bool isInteger(double v) {
        // checks if the double v represents an integer value
        double tmp;
        return std::modf(v, &tmp) == 0.0;
        // alternative less robust implementation
        // return  static_cast<double>(static_cast<long>(v)) == v;
    }

    int largestPalindrome(int n) {

        if (n == 1) return 9;

        const long max = pow(10, n);

        for (int z = 2; z < max - 1; z++) {
            const long left = max - z;
            const long right = flip(left);
            const double sqrt_term = z * z - 4 * right;

            // let's avoid generating nans applying the square root to negative numbers
            if (sqrt_term < 0.0) { continue; }

            const double root1 = 0.5 * (z + sqrt(sqrt_term));
            const double root2 = 0.5 * (z - sqrt(sqrt_term));

            if (isInteger(root1) || isInteger(root2)) {
                return (max * left + right) % 1337;
            }
        }
        // This should never be reached so we don't really care about what we return in here
        return -1;
    }
};

class _Solution {
public:
    bool isPalindrome(double p) {

        string s = to_string(p);
        int l = s.size();

        for (int i = 0; i < l; ++i) {
            if (s[i] == '.') {
                s = s.substr(0, i - 1);
                l = s.size();
                break;
            }
        }


        for (int i = 0; i < l / 2; ++i) {
            if (s[i] != s[l - i - 1]) return false;
        }

        return true;
    }


    int largestPalindrome(int n) {

        double m = 9;
        for (double i = 0; i < n-1; ++i) {
            m *= 10;
            m += 9;
        }

        double max_palindrome = 0;
        for (double i = m; i > 0; --i) {
            for (double j = m; j > 0; --j) {
                double prod = i * j;
                if (prod <= max_palindrome) continue;

                if (isPalindrome(prod)) {
                    max_palindrome = prod;
                }
            }
        }

        int div = max_palindrome / 1337;
        int rem = max_palindrome - 1337 * div;

        return rem;
    }
};

int main() {
    Solution sol;
    char c;

    cout << sol.largestPalindrome(6);

    cin >> c;
}
