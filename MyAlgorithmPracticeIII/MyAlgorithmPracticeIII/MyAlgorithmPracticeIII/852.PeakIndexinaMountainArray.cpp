// bsearch
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
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = arr.size();

        int st = 0, ed = l - 1;
        int m = (st + ed) / 2;
        while (!(arr[m - 1] < arr[m] && (arr[m] > arr[m + 1]))) {
            if (arr[m - 1] > arr[m]) {  // need to move left
                ed = m;
                m = (st + ed) / 2;
            }
            else {
                st = m;
                m = (st + ed) / 2;
            }
        }

        return m;
    }
};


int main() {
    char c;
    Solution sol;

    vector<int> arr = { 0, 1, 0 };

    cout << sol.peakIndexInMountainArray(arr);

    cin >> c;
}
