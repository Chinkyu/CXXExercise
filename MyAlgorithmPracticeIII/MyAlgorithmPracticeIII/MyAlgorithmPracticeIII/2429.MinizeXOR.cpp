// ok. 
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
#include <bit>

using namespace std;

int __builtin_popcount(unsigned int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1); // Clears the lowest set bit
        count++;
    }
    return count;
}



class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int c1 = __builtin_popcount(num1);
        int c2 = __builtin_popcount(num2);

        if (c1 > c2) {  // remove 1 from c1 (c1 - c2)
            int n = c1 - c2;

            for (int i = 0; n > 0 ; ++i) {
                int v = 0x01 << i;
                if ((num1 & v) == v) {
                    num1 -= v;
                    n--;
                }
            }
        }
        else if (c1 < c2) { // replace 0 to 1 from left (c2 - c1)
            int n = c2 - c1;

            for (int i = 0; n > 0; ++i) {
                int v = 0x01 << i;
                if ((num1 & v) == 0) {
                    num1 += v;
                    n--;
                }
            }

        } else{  // same
            //
        }

        return num1;
    }
};

int main() {
    char c;
    //vector<vector<int>> n = { { -2, -2, 1, 1},{2, 2, 4, 6} };
    vector<vector<int>> n = { { 1, 1, 5, 5} };

    Solution sol;

    cout << sol.minimizeXor(1, 12);

    cin >> c;
}
