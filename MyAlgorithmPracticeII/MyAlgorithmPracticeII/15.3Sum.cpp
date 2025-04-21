//  Saw answer : keeping find to answer... 
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

//Optimized Approach - O(n^2 logn + nlogn) - o(n^2 logn) time and O(n) space
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    s.insert({ nums[i], nums[j], nums[k] });
                    j++;
                    k--;
                }
                else if (sum < target) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        for (auto triplets : s)
            output.push_back(triplets);
        return output;
    }
};

// timeout
class _Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        vector<vector<int>> ans;

        for (auto it : nums) m[it]++;

        if (m.size() == 1 && nums[0] == 0) {
            ans.push_back({ 0, 0, 0 });
            return ans;
        }
        
        set<vector<int>> ans_set;
        for (int i = 0; i < nums.size() - 2; ++i) {
            unordered_map<int, int> m2 = m;
            m2[nums[i]]--;
            for (int j = i + 1; j < nums.size(); ++j) {
                m2[nums[j]]--;
                int r = (nums[i] + nums[j]) * -1;
                if (m2[r] > 0) {
                    vector<int> v{ nums[i], nums[j], r };
                    sort(v.begin(), v.end());
                    ans_set.insert(v);
                }
            }

        }


        for (auto it : ans_set) {
            ans.push_back(it);
        }

        return ans;
    }
};

// timeout
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, int> m;
        vector<vector<int>> ans;

        for (auto it : nums) m[it]++;

        vector<int> snums;
        for (auto it : m) snums.push_back(it.first);

        vector<vector<int>> ans_set;
        for (int i = 0; i < snums.size(); ++i) {
            map<int, int> m2 = m;
            m2[snums[i]]--;
            for (int j = 0; j < snums.size(); ++j) {
                if (m2[snums[j]] <= 0) continue;
                m2[snums[j]]--;

                int r = (snums[i] + snums[j]) * -1;
                if (m2[r] > 0) {
                    vector<int> v{ snums[i], snums[j], r };
                    sort(v.begin(), v.end());
                    ans_set.insert(v);
                }
            }

        }
       
        for (auto it : ans_set) {
            ans.push_back(it);
        }

        return ans;
    }
};



int main() {
    char c;
    Solution sol;
    vector<int> nums = { -1,0,1,2,-1,-4 };


    vector<vector<int>> ans =  sol.threeSum(nums);

    for (auto it : ans) {
        cout << it[0] << " " << it[1] << " " << it[2] << endl;
    }

    cin >> c;
}