// ´äÂüÁ¶ : 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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

/*
Initialize a step counter answer to 0.
While n > 1:

    If n is 3, return steps plus 2 directly because 3 -> 2 -> 1 is optimal.
    If n is INT_MAX (maximum integer value), decrement by 1 to avoid overflow.
    If n is even, divide by 2 (best step).
    Otherwise, check the parity of (n-1)/2:
        If (n-1)/2 is even, decrement n by 1 (makes the next number easier to divide).
        Else, increment n by 1.
    Increment the step counter each operation.

Return the total steps taken

*/


class Solution {
public:
    int integerReplacement(int n) {

        long long num = n;

        if (n == 3) return 2;

        int ans = 0;
        while (num > 1) {
            if (num & 0x01 == 0x01) {

                if (num == 3) {
                    ans += 2;
                    break;
                }

                if (((num-1)/2) % 2 == 0) { 
                    num--;
                }
                else {
                    num++;
                }
            }
            else {
                num /= 2;
            }
            ans++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    char c;

    cout << sol.integerReplacement(1234);

    cin >> c;
}
