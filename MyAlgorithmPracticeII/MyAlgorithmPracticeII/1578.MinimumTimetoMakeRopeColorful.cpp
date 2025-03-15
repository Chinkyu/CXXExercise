// ok : Remain only max in group

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
    int minCost(string colors, vector<int>& neededTime) {
        int l = colors.size();
        int ans = 0;

        char c = '-', pre_c = '-';
        int cnt = 0, tsum = 0, tmax = 0;
        for (int i = 0; i < l; ++i) {
            c = colors[i];
            if (pre_c == c) {
                cnt++;
                tsum += neededTime[i];
                tmax = max(tmax, neededTime[i]);
            }
            else {
                ans += tsum - tmax;
                
                cnt = 1;
                tsum = neededTime[i];
                tmax = neededTime[i];
                pre_c = c;
            }
        }

        if (cnt > 1) {
            ans += tsum - tmax;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

//    string colors = "abaac";
//    vector<int> needTime = { 1, 2, 3, 4, 5 };
    string colors = "aabaa";
    vector<int> needTime = { 1, 2, 3, 4, 1 };


    cout << sol.minCost(colors, needTime);

    cin >> c;
}