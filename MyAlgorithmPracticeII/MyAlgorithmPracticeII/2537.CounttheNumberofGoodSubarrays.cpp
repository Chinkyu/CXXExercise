// see anser : more efficient way to calcurate nCr
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <cmath>
#include <regex>
#include <memory>

using namespace std;


// timeout.... 
class _Solution {
public:
    bool isGoodSubarrayThanK(unordered_map<int, int>& m, int k) {
        int cnt = 0;
        for (auto& it : m) {
            if (it.second > 1) {
                cnt += (it.second * (it.second - 1)) / 2;
                if (cnt >= k) return true;
            }
        }

        return false;
    }


    long long countGood(vector<int>& nums, int k) {
        int l = nums.size();
        unordered_map<int, int> m;

        long long ans = 0;
        int st = 0,ed = 0;
        // make first ; ed not include.
        while (ed < l) {
            m[nums[ed]]++;
            ed++;

            if (isGoodSubarrayThanK(m, k)) {
                ans += l - ed + 1;
                break;
            }
        }
        //if (ed >= l) return ans;

        for (int i = 0; i < l; ++i) {
            m[nums[i]]--;
            st = i + 1;

            // check only after remove
            if (isGoodSubarrayThanK(m, k)) {
                ans += l - ed + 1;
                continue;
            }

            // if not, increase ed
            while (ed < l) {
                m[nums[ed]]++;
                ed++;

                if (isGoodSubarrayThanK(m, k)) {
                    ans += l - ed + 1;
                    break;
                }
            }

            if (ed >= l && !isGoodSubarrayThanK(m, k)) return ans;
        }

        return ans;
    }
};


// more simple way co calculate  nCr
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long res = 0;
        for (int left = 0, right = 0, n = nums.size(); right < n; ++right) {
            k -= freq[nums[right]]++;
            while (k <= 0) {
                res += n - right;
                k += --freq[nums[left++]];
            }
        }
        return res;
    }
};


int main() {
    char c;
    Solution sol;
    vector<int> nums = { 2,3,1,3,2,3,3,3,1,1,3,2,2,2 };

    cout << sol.countGood(nums, 18);

    std::cin >> c;
}