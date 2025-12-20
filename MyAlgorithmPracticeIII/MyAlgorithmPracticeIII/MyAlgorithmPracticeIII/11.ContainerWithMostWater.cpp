// Ok.. : only count  seeable hight from left and right 
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
#include <random>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = height.size();
        vector<int> le, ri;

        int tmax = height[0];
        le.push_back(0);
        for (int i = 1; i < l; ++i) {
            if (height[i] > tmax) {
                le.push_back(i);
                tmax = height[i];
            }
        }

        tmax = height[l - 1];
        ri.push_back(l-1);
        for (int i = l - 2; i >= 0; --i) {
            if (height[i] > tmax) {
                ri.push_back(i);
                tmax = height[i];
            }
        }


        // check all combinations amd find max
        int ans = 0;
        for (int i = 0; i < le.size(); ++i) {
            for (int j = 0; j < ri.size(); ++j) {
                int h = min(height[le[i]], height[ri[j]]);
                ans = max(ans, h * abs(le[i] - ri[j]));
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> height = { 1,8,6,2,5,4,8,3,7 };
    cout << sol.maxArea(height);


    cin >> c;
}
