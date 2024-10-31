// too easy : excpet special case : 
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
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {

        int tmax = 0;

        tmax = max(tmax, abs(sx - fx));
        tmax = max(tmax, abs(sy - fy));


        if (sx == fx && sy == fy && t - tmax == 1) return false;  // special case 

        if (t >= tmax) {
            return true;
        }


        return false;
    }
};

int main() {
    char c;
    Solution sol;

    cout << sol.isReachableAtTime(1, 2, 1, 2, 1);

    cin >> c;
}