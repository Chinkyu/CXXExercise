// see answer : pq. 
//   
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
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int l = nums1.size();
        vector<vector<int>> v;
        map<int, int> m;

        for (int i = 0; i < l; ++i) {
            v.push_back({ nums1[i], nums2[i], i });
            m[nums2[i]]++;
        }

        sort(v.rbegin(), v.rend()); // reverse sorting. 

        vector<long long> ans(l, 0);
        vector<int> same_value_index;  // to handle same nums1 value
        for (int i = 0; i < l; ++i) {
            int oi = v[i][2];
            m[nums2[oi]]--;
            if (m[nums2[oi]] == 0) m.erase(nums2[oi]);
            if (i + 1 < l && v[i][0] == v[i + 1][0]) {
                //ans[v[i + 1][2]] = ans[oi];
                same_value_index.push_back(v[i][2]);
                same_value_index.push_back(v[i + 1][2]);
                continue;
            }

            long long subs = 0;
            int cnt = k;
            auto it = m.rbegin();
            while (it != m.rend() && cnt > 0) {
                if (cnt >= it->second) {
                    subs += it->first * it->second;
                    cnt -= it->second;
                }
                else {
                    subs += it->first * cnt;
                    cnt -= cnt;
                }
                it++;
            }
            ans[oi] = subs;
            if (same_value_index.size() > 0) {
                for (auto& it : same_value_index) ans[it] = subs;
                same_value_index.clear();
            }
        }

        return ans;

    }
};
// timeout...  k개 그때 그때 계산 하면 안되고... maintain 해야..
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int l = nums1.size();
        vector<vector<int>> v;
        map<int, int> m;

        for (int i = 0; i < l; ++i) {
            v.push_back({ nums1[i], nums2[i], i });
            m[nums2[i]]++;
        }

        sort(v.rbegin(), v.rend()); // reverse sorting. 

        vector<long long> ans(l, 0);
        vector<int> same_value_index;  // to handle same nums1 value
        for (int i = 0; i < l; ++i) {
            int oi = v[i][2];
            m[nums2[oi]]--;
            if (m[nums2[oi]] == 0) m.erase(nums2[oi]);
            if (i + 1 < l && v[i][0] == v[i + 1][0]) {
                //ans[v[i + 1][2]] = ans[oi];
                same_value_index.push_back(v[i][2]);
                same_value_index.push_back(v[i+1][2]);
                continue;
            }

            long long subs = 0;
            int cnt = k;
            auto it = m.rbegin();
            while(it != m.rend() && cnt > 0) {
                if (cnt >= it->second) {
                    subs += it->first * it->second;
                    cnt -= it->second;
                }
                else {
                    subs += it->first * cnt;
                    cnt -= cnt;
                }
                it++;
            }
            ans[oi] = subs;
            if (same_value_index.size() > 0) {
                for (auto& it : same_value_index) ans[it] = subs;
                same_value_index.clear();
            }
        }

        return ans;

    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums1 = { 18,11,24,9,10,11,7,29,16 };
    vector<int> nums2 = { 28,26,27,4,2,19,23,1,2 };

    vector<long long> ans = sol.findMaxSum(nums1, nums2, 1);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
