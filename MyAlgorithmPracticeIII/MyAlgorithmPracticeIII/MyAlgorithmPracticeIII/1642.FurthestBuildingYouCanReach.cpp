// its very tricky  to overcome timeout ; use priority que to maintain max 
//   
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


// 타입 아웃이네......  앞에서 차레로 하니까 그런거 아닌가???????
class _Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int l = heights.size();
        vector<int> a(l, 0);

        for (int i = 1; i < l; ++i) {
            if (heights[i] - heights[i - 1] > 0) {
                a[i] = heights[i] - heights[i - 1];
            }
        }

        int idx = 0;
        int rbricks = bricks;
        int tmax = -1, tmaxidx = -1;
        for (int i = 0; i < ladders; ++i) {
            for (int j = idx; j < l; ++j) {
                if (rbricks < a[j]) {  // end   -> remove max one 
                    if (a[j] > tmax) {
                        tmax = a[j];
                        tmaxidx = j;
                        if (tmaxidx != j) rbricks += a[j];
                    }

                    // remove max ladder
                    a[tmaxidx] = 0;
                    break;
                }

                rbricks -= a[j];
                if (a[j] > tmax) {
                    tmax = a[j];
                    tmaxidx = j;
                }
                idx = j;
            }
        }

        tmax = -1;
        tmaxidx = -1;
        rbricks = bricks;
        idx = -1;
        for (int j = 0; j < l; ++j) {
            if (rbricks < a[j]) {  // end   -> remove max one 
                idx = j - 1;
                break;
            }
            rbricks -= a[j];
        }

        if (idx == -1) idx = l - 1;
        return idx;
    }
};

// timeout  tool.... 
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int l = heights.size();
        vector<int> a(l, 0);

        for (int i = 1; i < l; ++i) {
            if (heights[i] - heights[i - 1] > 0) {
                a[i] = heights[i] - heights[i - 1];
            }
        }

        int idx = 0;
        int rbricks = bricks;
        priority_queue<int> pq;
        for (int i = 0; i < ladders; ++i) {
            if (idx == l - 1) break;
            for (int j = idx; j < l; ++j) {
                if (rbricks < a[j]) {  // end   -> remove max one 
                    if (pq.size() == 0 || a[j] > pq.top()) {
                        a[j] = 0;
                    }
                    else {
                        rbricks += pq.top();
                        pq.pop();
                    }
                    idx = j;
                    break;
                }

                rbricks -= a[j];
                if (a[j] > 0) pq.push(a[j]);
                idx = j;
            }
        }

        for (int j = idx; j < l; ++j) {
            if (rbricks < a[j]) {  // end   -> remove max one 
                idx = j - 1;
                break;
            }
            rbricks -= a[j];
            idx = j;
        }

        if (idx == -1) idx = l - 1;
        return idx;
    }
};

int main() {
    char c;
    Solution sol;

    //vector<int> heights = { 4,2,7,6,9,14,12 };
    // vector<int> heights = { 14,3,19,3 };
    vector<int> heights = { 1,13,1,1,13,5,11,11 };

    cout << sol.furthestBuilding(heights, 10, 8);

    cin >> c;
}
