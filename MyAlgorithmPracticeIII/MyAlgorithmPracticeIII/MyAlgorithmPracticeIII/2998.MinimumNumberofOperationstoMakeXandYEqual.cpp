// see answer

/*
When x > y, we have 4 options.

    plus then divide 5
    minus then divide 5
    plus then divide 11
    minus then divide 11
*/


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


//:: ckkang : 5 + 1, 11 + 1 은 추가로 Add 되면서 11 x (x + 1) 이 되니까.... 이렇게 함. 

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x <= y)
            return y - x;
        int res = x - y;
        res = min(res, minimumOperationsToMakeEqual(x / 5, y) + 1 + x % 5);
        res = min(res, minimumOperationsToMakeEqual(x / 5 + 1, y) + 1 + 5 - x % 5);
        res = min(res, minimumOperationsToMakeEqual(x / 11, y) + 1 + x % 11);
        res = min(res, minimumOperationsToMakeEqual(x / 11 + 1, y) + 1 + 11 - x % 11);
        return res;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 2,1,3,2,1,3 };

    cout << sol.maximumMedianSum(nums);

    cin >> c;
}
