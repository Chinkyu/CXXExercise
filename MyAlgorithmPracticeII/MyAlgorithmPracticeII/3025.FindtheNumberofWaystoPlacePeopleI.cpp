// see answer : 
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
    int numberOfPairs(vector<vector<int>>& points) {
        // Sort by x ascending, and if tie, y descending
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
            });

        int n = points.size();
        int ans = 0;

        // Iterate over all left points
        for (int i = 0; i < n - 1; i++) {
            int pi2 = points[i][1];
            int minh = INT_MIN;

            // Check right-side points
            for (int j = i + 1; j < n; j++) {
                if (points[j][1] > minh && points[j][1] <= pi2) {
                    ans++;
                    minh = points[j][1];
                }
            }
        }
        return ans;
    }
};

class _Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int l = points.size();

        int ans = 0;
        for (int i = 0; i < l - 1; ++i) {
            for (int j = i + 1; j < l; ++j) {
                if ((points[i][0] <= points[j][0]) &&
                    (points[i][1] >= points[j][1])) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    char c;
    vector<vector<int>> points = { {6, 2}, {4, 4}, {2, 6} };

    cout << sol.numberOfPairs(points);

    cin >> c;
}
