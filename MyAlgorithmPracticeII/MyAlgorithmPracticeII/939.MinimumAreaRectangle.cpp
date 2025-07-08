// ´äºÃÀ½... x1, y1,   x2, y2  -> x1,y2, x2, y1 existance checking
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
#include <iostream>

using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> pointSet;
        const int OFFSET = 40001;
        int res = INT_MAX, n = points.size();
        for (int i = 0; i < n; ++i) pointSet.insert(points[i][0] * OFFSET + points[i][1]);
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 || y1 == y2) continue;
                int key1 = x1 * OFFSET + y2;
                int key2 = x2 * OFFSET + y1;
                if (pointSet.count(key1) && pointSet.count(key2)) res = min(res, abs(x1 - x2) * abs(y1 - y2));
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1, 10, 2, 9 };


    cout << sol.minMoves2(nums);

    cin >> c;
}