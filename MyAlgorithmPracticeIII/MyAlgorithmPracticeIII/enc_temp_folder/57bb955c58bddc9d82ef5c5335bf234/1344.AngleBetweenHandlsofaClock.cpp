// 문제 이상함 : 이게 맞는것 같음. 
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

        double ans = abs(ha - ma);
        if (ans > 180) ans -= 180;

        return ans;

    }
};

int main() {
    char c;
    Solution sol;


    cout << sol.angleClock(1, 57);


    cin >> c;
}
