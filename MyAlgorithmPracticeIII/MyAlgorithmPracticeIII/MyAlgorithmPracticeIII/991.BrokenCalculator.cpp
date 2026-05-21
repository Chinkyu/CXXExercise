// see answer : from target... 

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
#include <bit>

using namespace std;


// start 에서 부티 시작 하면 아안되고 Target 부터 시작해야한다고함. 
class _Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;

        int m = startValue;
        while (m < target) {
            m *= 2;
            ans++;
        }

        ans += m - target;
        return ans;

    }
};

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;

        int m = startValue;
        while (target > startValue) {
            ans++;
            if (target % 2 == 1) {
                target++;
            }
            else {
                target /= 2;
            }
        }

        return ans + startValue - target;
    }
};


int main() {
    char c;
    Solution sol;
      
    cout << sol.brokenCalc(5, 8);

    cin >> c;
}

