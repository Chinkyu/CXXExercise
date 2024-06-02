// not hard.... : mass fixing is problem 
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

using namespace std;

class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {

        int in = (loginTime[0] - '0') * 10 + loginTime[1] - '0';
        int in_hour = in;
        in *= 4;
        int in_min = (loginTime[3] - '0') * 10 + loginTime[4] - '0';
        in += ceil(  (double)((loginTime[3] - '0') * 10 + loginTime[4] - '0')/15);

        int out = (logoutTime[0] - '0') * 10 + logoutTime[1] - '0';
        int out_hour = out;
        out *= 4;
        int out_min = (logoutTime[3] - '0') * 10 + logoutTime[4] - '0';
        out += (((logoutTime[3] - '0') * 10 + logoutTime[4] - '0') / 15);

        int ans = out - in;
        if (ans == -1 && in_hour <= out_hour && in_min < out_min) return 0;
        ans =  (ans < 0) ? ans + 96 : ans;
        ans %= 96;
        //;if (ans == 95 && in < out) ans = 0;

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    //string loginTime = "21:30", logoutTime = "03:00";
    //string loginTime = "00:01", logoutTime = "00:00";
    //string loginTime = "00:00", logoutTime = "23:59";
    string loginTime = "00:47", logoutTime = "00:57";

    cout << sol.numberOfRounds(loginTime, logoutTime);

    cin >> c;
}