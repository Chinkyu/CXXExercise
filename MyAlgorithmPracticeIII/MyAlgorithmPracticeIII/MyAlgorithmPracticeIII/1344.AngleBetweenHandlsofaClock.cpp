// Ok...  find diff angle... is trickyu.....  360 round up
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
#include <chrono>
#include <iterator>

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {


        double ha = (360. / 12) * hour + (360. / 12) * (minutes / 60.);

        double ma = (minutes / 60.) * 360;

        if (ha >= 360) ha -= 360.;
        if (ma >= 360) ha -= 360.;

        double ans = ha - ma;
        ans = fmod(ans, 360.);

        if (ans > 180.0) ans -= 360;
        if (ans < -180.0) ans += 360;

        return abs(ans);

    }
};


int main() {
    char c;
    Solution sol;


    cout << sol.angleClock(1, 57);


    cin >> c;
}
