// see answer : simple rather than expected 
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


// 생각보다 너무 간단한데....
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, ans = 0;
        while (j < nums.size()) {
            if (nums[j] > nums[i]) { i++; ans++; }
            j++;
        }
        return ans;
    }
};


// Map  으로 다시하자.. 
class _Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int l = nums.size();
        vector<pair<int, int>> v;

        for (int i = 0; i < l; ++i) {
            v.push_back(make_pair(nums[i], i));
        }

        sort(v.begin(), v.end());
        map<int, int> m;
        for (int i = 0; i < l; ++i) {
            m[v[i].second] = i;
        }

        vector<int> vis(l, 0);
        int ans = 0;

        for (int i = 0; i < l; ++i) {
            int idx = m[i] + 1;
            while (idx < l && v[++idx].first > nums[i] && vis[idx] == 1) idx++;


                vis[idx] = 1;
                ans++;
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 3, 1, 2 };
    cout << sol.uniqueXorTriplets(nums);

    cin >> c;
}
