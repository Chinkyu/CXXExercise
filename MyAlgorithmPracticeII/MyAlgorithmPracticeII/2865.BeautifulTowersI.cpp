// ok :  이걸 다 해 봐도 되네..... 하여간...  디버깅... 
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <cmath>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:

    long long getMountain(vector<int>& heights, int tidx) {
        int l = heights.size();
        long long ans = heights[tidx];;

        // to left
        int t = heights[tidx];
        for (int i = tidx - 1; i >= 0; --i) {
            if (heights[i] < t) {
                t = heights[i];
            }
            ans += t;
        }

        // to right
        t = heights[tidx];
        for (int i = tidx + 1; i < l; ++i) {
            if (heights[i] < t) {
                t = heights[i];
            }
            ans += t;
        }

        return ans;
    }


    long long maximumSumOfHeights(vector<int>& heights) {
        int l = heights.size();
        vector<int> iv(l, 0);
        long long ans = 0;

        for (int i = 0; i < l; ++i) iv[i] = i;
        
        sort(iv.begin(), iv.end(), [=](int left, int right) {
            return heights[left] > heights[right];
            });

        for (int i = 0; i < iv.size(); ++i) {
            ans = max(ans, getMountain(heights, iv[i]));
        }

        return ans;
    }


    long long _2_maximumSumOfHeights(vector<int>& heights) {
        int l = heights.size();

        int tmax = heights[0], tidx = 0;

        vector<int> idxs;
        idxs.push_back(0);
        for (int i = 1; i < l; ++i) {
            if (tmax < heights[i]) {
                idxs.clear();
                idxs.push_back(i);
                tmax = heights[i];
            }
            else if(tmax == heights[i]) {
                idxs.push_back(i);
            }
        }

        long long ans = 0;
        for (int i = 0; i < idxs.size(); ++i) {
            ans = max(ans, getMountain(heights, idxs[i]));
        }


        return ans;
    }


    long long _maximumSumOfHeights(vector<int>& heights) {
        int l = heights.size();

        int tmax = heights[0], tidx = 0;
        for (int i = 1; i < l; ++i) {
            if (tmax < heights[i]) {
                tmax = heights[i];
                tidx = i;
            }
        }

        long long ans = tmax;

        // to left
        int t = tmax;
        for (int i = tidx - 1; i >= 0; --i) {
            if (heights[i] < t) {
                t = heights[i];
            }
            ans += t;
        }

        // to right
        t = tmax;
        for (int i = tidx + 1; i < l; ++i) {
            if (heights[i] < t) {
                t = heights[i];
            }
            ans += t;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> heights = {5, 5, 3, 2, 6 };

    cout << sol.maximumSumOfHeights(heights);

    std::cin >> c;
}