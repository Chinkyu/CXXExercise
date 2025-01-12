//  ¥‰∫√¿Ω : sorting and priority queue
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
    int minGroups(vector<vector<int>>& intervals) {
        // Convert the intervals to two events
        // start as {start, 1} and end as {end, -1}
        vector<pair<int, int>> intervalsWithEnd;
        for (vector<int> interval : intervals) {
            intervalsWithEnd.push_back({ interval[0], 1 });
            intervalsWithEnd.push_back({ interval[1] + 1, -1 });
        }

        // Sort the events according to the number and then by the value (1/-1).
        sort(intervalsWithEnd.begin(), intervalsWithEnd.end());

        int concurrentIntervals = 0;
        int maxConcurrentIntervals = 0;
        for (auto p : intervalsWithEnd) {
            // Keep track of currently active intersecting intervals.
            concurrentIntervals += p.second;
            // Update the maximum number of active intervals.
            maxConcurrentIntervals =
                max(maxConcurrentIntervals, concurrentIntervals);
        }

        return maxConcurrentIntervals;
    }
};

class _Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int l = intervals.size();

        sort(intervals.begin(), intervals.end(), [](vector<int>& l, vector<int>& r) {
            if (l[0] == r[0]) return l[1] > r[1];
            return l[0] < r[0];

            });

        int max_overlap = 0;
        for (int i = 0; i < l - 1; ++i) {
            int overlap = 0;
            for (int j = i + 1; j < l; ++j) {
                if (intervals[i][1] < intervals[j][0]) break;
                if (intervals[i][1] >= intervals[j][0]) overlap++;
            }

            max_overlap = max(max_overlap, overlap);
        }

        return max_overlap;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> intervals = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};


    cout << sol.minGroups(intervals);

    cin >> c;
}