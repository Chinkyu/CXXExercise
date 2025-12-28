// ok : 

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
    int minOperations(vector<int>& nums) {
        map<int, int> m;

        for (auto& it : nums) {
            m[it]++;
        }

        int ans = 0;
        for (auto& it : m) {
            if (it.second < 2) return -1;

            ans += it.second / 3;
            if (it.second % 3 > 0) ans++;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 2,3,3,2,2,4,2,3,4 };

    cout << sol.minOperations(nums);


    cin >> c;
}
