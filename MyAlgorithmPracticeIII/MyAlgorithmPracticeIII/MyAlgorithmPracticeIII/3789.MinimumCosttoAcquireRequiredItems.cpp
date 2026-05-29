// see answer 
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
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long min, max, ans;
        min = fmin(need1, need2);
        max = fmax(need1, need2);

        // 각각 사기
        ans = (long long)need1 * cost1 + (long long)need2 * cost2;

        // 최소 공동으로 사기 
        ans = fmin(ans, (long long)min * costBoth + (long long)(need1 - min) * cost1 + (long long)(need2 - min) * cost2);

        // 최대 공동으로 사기 
        ans = fmin(ans, (long long)max * costBoth);
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> seats = { 1, 0, 0 , 0 };

    cout << sol.maxDistToClosest(seats);

    cin >> c;
}
