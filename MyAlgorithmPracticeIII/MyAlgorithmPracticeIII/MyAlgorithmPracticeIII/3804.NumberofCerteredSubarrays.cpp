// ok : sliding windows 
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
#include <chrono>
#include <iterator>

using namespace std;

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int l = nums.size();
        unordered_map<int, int> m;

        if (l == 1) return 1;

        int ans = 0;
        for (int i = 0; i < l; ++i) {
            m.clear();
            m[nums[i]]++;
            ans++;
            int sum = nums[i];
            for (int j = i + 1; j < l; ++j) {
                m[nums[j]]++;
                sum += nums[j];

                if (m.find(sum) != m.end()) {
                    ans++;
                }
            }

        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = 
    //{ 0, 1 };
    { -1, 1, 0 };

    cout << sol.centeredSubarrays(nums);

    cin >> c;
}
