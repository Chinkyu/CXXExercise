// 답봤음... : what binary search????
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
    int findMin(vector<int>& v) {
        int l = 0, h = v.size() - 1;
        while (l < h)
        {
            int m = (l + h) / 2;
            if (v[m] > v[h]) {
                l = m + 1;
            }
            else if (v[l] < v[m])
            {
                h = m - 1;
            }
            else
            {
                h--;
            }
        }
        return v[l];
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> heights = { 2,1,5,6,2,3 };

    cout << sol.largestRectangleArea(heights);

    cin >> c;
}