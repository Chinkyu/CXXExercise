// see answer :  
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
    int maximumElementAfterDecrementingAndRearranging(vector<int>& A) {
        sort(A.begin(), A.end());
        int pre = 0;
        for (int& a : A)
            pre = min(pre + 1, a);
        return pre;
    }
};

int main() {
    char c;
    Solution sol;

    //vector<int> nums = { 0,3,7,2,5,8,4,6,0,1 };

    cout << sol.trailingZeroes(5);

    cin >> c;
}
