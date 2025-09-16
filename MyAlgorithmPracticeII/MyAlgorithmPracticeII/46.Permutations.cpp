// ok :
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
#include <iostream>

using namespace std;

class Solution {
public:

    void traverse(vector < vector<int>>& ans, vector<int>& nums, int l, vector<int>& tmap, vector<int> & permu, int pi) {

        if (l == pi) {
            ans.push_back(permu);
            return;
        }

        for (int i = 0; i < l; ++i) {
            if (tmap[i] == 1) continue;
            tmap[i] = 1;
            permu[pi] = nums[i];
            traverse(ans, nums, l, tmap, permu, pi + 1);
            tmap[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int l = nums.size();
        vector<int> permu(l, 0);
        vector<int> tmap(l, 0);

        vector<vector<int>> ans;
        traverse(ans, nums, l, tmap, permu, 0);

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> nums = { 1, 2, 3 };


    vector<vector<int>> ans = sol.permute(nums);
    for (auto& it : ans) {
        for (auto& jt : it) {
            cout << jt << " ";
        }
        cout << endl;
    }

    cin >> c;
}