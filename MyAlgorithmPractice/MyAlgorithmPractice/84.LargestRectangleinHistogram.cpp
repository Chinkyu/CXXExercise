// add sticky condition make pass
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
    int largestRectangleArea(vector<int>& heights) {
        int l = heights.size();

        int max_space = 0;
        int pre_height = 0;
        for (int i = 0; i < l; ++i) {
            int space = heights[i];

            if (i > 0 && heights[i] == heights[i - 1]) continue;

            // left
            if (i > 0 && heights[i - 1] > heights[i]) {
                for (int j = i - 1; j >= 0; --j) {
                    if (heights[j] >= heights[i]) {
                        space += heights[i];
                    }
                    else {
                        break;
                    }
                }
            }

            // right
            for (int j = i+1; j < l; ++j) {
                if (heights[j] >= heights[i]) {
                    space += heights[i];
                }
                else {
                    break;
                }
            }

            pre_height = heights[i];
            max_space = max(max_space, space);
        }

        return max_space;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> heights = { 2,1,5,6,2,3 };

    cout << sol.largestRectangleArea(heights);

    cin >> c;
}