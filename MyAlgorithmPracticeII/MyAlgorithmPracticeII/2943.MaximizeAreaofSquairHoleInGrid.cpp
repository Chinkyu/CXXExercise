//  답봤음 : 정사각형만??? 
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
    int getMaxGap(vector<int> bars) {
        sort(bars.begin(), bars.end());
        int count = 2, res = 2;
        for (int i = 1; i < bars.size(); ++i) {
            count = (bars[i - 1] + 1 == bars[i]) ? count + 1 : 2;
            res = max(res, count);
        }
        return res;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int gap = min(getMaxGap(hBars), getMaxGap(vBars));
        return gap * gap;
    }
};
int main() {
    char c;
    Solution sol;
    vector<int> arr = { 1, 3, 5 };


    cout << sol.numOfSubarrays(arr);

    cin >> c;
}