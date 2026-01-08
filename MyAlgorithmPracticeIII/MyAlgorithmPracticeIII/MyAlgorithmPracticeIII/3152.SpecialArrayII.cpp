// ok : use count array when different parity
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
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int l = nums.size();
        vector<int> st(l, 0);

        //if(l == 0) 

        for (int i = 1, cnt = 0; i < l; ++i) {
            if ((nums[i - 1] & 0x01) ^ (nums[i] & 0x01)) {
                st[i] = ++cnt;
            }
            else {
                st[i] = cnt;
            }
        }

        vector<bool> ans;
        for (auto& it : queries) {

            if ((it[1] - it[0]) == st[it[1]] - st[it[0]]) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    
    vector<int> nums = { 4, 3, 1, 6 };
    vector<vector<int>> queries = { {0, 2}, {2, 3} };

    vector<bool> ans = sol.isArraySpecial(nums, queries);

    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
