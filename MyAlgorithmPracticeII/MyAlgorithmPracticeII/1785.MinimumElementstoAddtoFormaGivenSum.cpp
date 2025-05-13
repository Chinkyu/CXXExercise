//  ok  
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
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;

        for(auto &it : nums) { 
            sum += it;
        }

        long long delta = abs(goal - sum);

        int ans = 0;
        ans += delta / limit;
        if (delta % limit > 0) ans++;

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> nums = { 1,-10,9,1 };

    cout << sol.minElements(nums, 100, 0);

    cin >> c;
}