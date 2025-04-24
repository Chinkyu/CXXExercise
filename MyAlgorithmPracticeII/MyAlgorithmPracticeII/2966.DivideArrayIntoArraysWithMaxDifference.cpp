//  easy : really ? 
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
#include <set>
#include <list>
#include <regex>
#include <memory>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i = i + 3) {
            if (nums[i + 2] - nums[i] > k) {
                ans.clear();
                return ans;
            }

            ans.push_back({ nums[i], nums[i + 1], nums[i + 2] });
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<vector<int>> grid = { {1, 3, 1}, {1, 5, 1}, {4, 2, 1} };
    vector<vector<int>> grid = { {0} };

    cout << sol.minPathSum(grid);

    cin >> c;
}