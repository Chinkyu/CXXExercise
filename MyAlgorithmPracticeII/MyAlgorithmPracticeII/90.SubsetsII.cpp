// ok : but it need to sort vector that doesn't spefied in problem 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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


// 
class _Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int l = nums.size();
        set<vector<int>>  s;

        for (int i = 0; i < l; ++i) {
            for (int j = i; j <= l; ++j) {
                s.insert(vector<int>(nums.begin() + i, nums.begin() + j));
            }
        }

        vector<vector<int>> ans;
        //ans.push_back(vector<int>());
        for (auto& it : s) {
            ans.push_back(it);
        }

        return ans;
    }
};


class Solution {
public:
    set<vector<int>>  s;

    void traverse(vector<int> & nums, vector<int> &flag, int i, int l) {

        if (i == l) {
            vector<int> v;
            for (int i = 0; i < l; ++i) {
                if (flag[i] == 1) {
                    v.push_back(nums[i]);
                }
            }
            sort(v.begin(), v.end());

            s.insert(v);
            return;
        }


        // 0
        flag[i] = 0;
        traverse(nums, flag, i + 1, l);

        // 1
        flag[i] = 1;
        traverse(nums, flag, i + 1, l);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int l = nums.size();
        s.clear();

        vector<int> flag(l, 0);

        traverse(nums, flag, 0, l);

        vector<vector<int>> ans;
        //ans.push_back(vector<int>());
        for (auto& it : s) {
            ans.push_back(it);
        }

        return ans;
    }
};



int main() {
    Solution sol;
    char c;

    vector<int> nums = { 1, 2, 2 };

    vector<vector<int>> ans = sol.subsetsWithDup(nums);
    for (auto& it : ans) {
        for (auto& jt : it) {
            cout << jt << " ";
        }
        cout << endl;
    }


    cin >> c;
}
