//  easy 
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
    long long minimumRemoval(vector<int>& beans) {
        int l = beans.size();
        sort(beans.begin(), beans.end());

        long long ls = 0, rs = 0;
        for (int i = 1; i < l; ++i) rs += beans[i];

        long long lowremove = rs - ((long long)beans[0] * (l - 1));
        for (int i = 1; i < l; ++i) {
            ls += beans[i-1];
            rs -= beans[i];

            long long cremove = ls + rs - ((long long)beans[i] * (l - i - 1));

            lowremove = min(lowremove, cremove);


        }

        return lowremove;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 2, 10, 3, 2 };

    cout << sol.minimumRemoval(nums);

    cin >> c;
}