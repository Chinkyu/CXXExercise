//  ¥‰∫√¿Ω : binary search 
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
    vector<int> a;
    int n;
    int d;

    // Check if it is possible to ship within 'd' days with the given capacity 'cap'
    bool possible(int cap) {
        int wt = 0;
        int day = 1; // Start with day 1 (at least 1 day is required)

        for (int i = 0; i < n; i++) {
            if (a[i] > cap) {
                return false; // If any package exceeds the capacity, it's not possible
            }

            if (wt + a[i] > cap) {
                day++;  // Need an extra day
                wt = 0;
            }

            wt += a[i];
        }

        return (day <= d);  // Return true if within the day limit
    }

    int shipWithinDays(vector<int>& wt, int days) {
        d = days;
        a = wt;
        n = wt.size();

        int sum = 0;
        int maxWt = 0;
        for (int it : wt) {
            sum += it;
            maxWt = max(maxWt, it);
        }

        // Lower bound is the heaviest package, upper bound is the total weight sum
        int l = maxWt;
        int r = sum;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (possible(mid)) {
                r = mid; // Try to minimize capacity
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }
};



int main() {
    char c;
    Solution sol;

    vector<int> customers = { 1,0,1,2,1,1,7,5 };
    vector<int> grumpy = { 0,1,0,1,0,1,0,1 };

    cout << sol.maxSatisfied(customers, grumpy, 3);

    cin >> c;
}