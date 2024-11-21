//  ¥‰∫√¿Ω..... 
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
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int n = buses.size(), m = passengers.size();

        int res = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            int cnt = 0;
            while (j < m && passengers[j] <= buses[i] && cnt < capacity) {
                ++cnt;
                ++j;
            }
            if (i == n - 1) { // the last bus
                if (cnt < capacity) { // still have seats
                    int t = buses[i]; // can be as late as the bus arrive time
                    for (int k = j - 1; k >= 0 && passengers[k] == t; --k, --t);
                    res = max(res, t);
                }
                else { // full of passegers
                    int t = passengers[j - 1] - 1; // should arrive earlier than last passenger aboard
                    for (int k = j - 2; k >= 0 && passengers[k] == t; --k, --t);
                    res = max(res, t);
                }
            }
        }

        return res;
    }
};

// complicate
class _Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {

        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        int wi = 0;

        for (int i = 0; i < buses.size(); ++i) {

            for (int j = 0; j < passengers.size(); ++j) {

                if (buses[i] < passengers[j]) {
                    if (j - wi <= capacity) {
                        wi = j;
                    }
                    else {
                        wi = wi + capacity;
                    }
                }

            }
        }


    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1, 2, 3, 4, 5 };

    cout << sol.minimumAverageDifference(nums);

    cin >> c;
}