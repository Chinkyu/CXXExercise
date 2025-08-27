//  easy : similar been solved
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
    int minOperations(vector<int>& nums) {
        int l = nums.size();

        int ans = (nums[0] == 0) ? 1 : 0;
        int pre = nums[0];

        for (int i = 1; i < l; ++i) {
            if (nums[i] != pre) {
                ans++;
                pre = nums[i];
            }
        }
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    string s = "aaab";

    cout << sol.reorganizeString(s);

    cin >> c;
}