//  답참조 : 4보다 크면 break 가 timeout 없앴음. 
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


// timeout 
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            set<int> s;
            s.insert(1);
            s.insert(nums[i]);
            for (int j = 2; j < nums[i] / 2; ++j) {
                if (nums[i] % j == 0) {
                    s.insert(j);
                    s.insert(nums[i] / j);
                }
                if (s.size() > 4) break;
            }
            if (s.size() == 4) {
                for (auto& it : s) {
                    ans += it;
                }
            }
        }

        return ans;
    }
};


int main() {
    char c;
    Solution sol;
    vector<int> nums = { 21, 21, 4, 7};

    cout << sol.sumFourDivisors(nums);

    cin >> c;
}