// reference answer :  set make timeout , but min, max main tain 
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

// Monotonic stack.. using 
class _Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long answer = 0;
        stack<int> stk;

        // Find the sum of all the minimum.
        for (int right = 0; right <= n; ++right) {
            while (!stk.empty() &&
                (right == n || nums[stk.top()] >= nums[right])) {
                int mid = stk.top();
                stk.pop();
                int left = stk.empty() ? -1 : stk.top();
                answer -= (long long)nums[mid] * (right - mid) * (mid - left);
            }
            stk.push(right);
        }

        // Find the sum of all the maximum.
        stk.pop();
        for (int right = 0; right <= n; ++right) {
            while (!stk.empty() &&
                (right == n || nums[stk.top()] <= nums[right])) {
                int mid = stk.top();
                stk.pop();
                int left = stk.empty() ? -1 : stk.top();
                answer += (long long)nums[mid] * (right - mid) * (mid - left);
            }
            stk.push(right);
        }
        return answer;
    }
};


// timeout -> tmorrow.. 
class __Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int l = nums.size();

        long long ans = 0;

        for (int i = 2; i <= l; ++i) {
            multiset<int> ms;

            // initial
            for (int j = 0; j < i; ++j) {
                ms.insert(nums[j]);
            }

            // max - min
            ans += *ms.rbegin() - *ms.begin();


            // move one by one
            for (int j = 0; j + i < l; ++j) {
                auto it = ms.find(nums[j]);

                // remove
                if (it != ms.end()) {
                    ms.erase(it); // Removes only that specific instance
                }

                // add 
                ms.insert(nums[j + i]);

                // max - min
                ans += *ms.rbegin() - *ms.begin();

            }
        }

        return ans;
    }
};

// set Àº Timeout.. 
class ___Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int l = nums.size();

        long long ans = 0;

        for (int i = 0; i < l - 1; ++i) {

            multiset<int> ms;

            ms.insert(nums[i]);
            for (int j = i + 1; j < l; ++j) {
                ms.insert(nums[j]);

                // max - min
                ans += *ms.rbegin() - *ms.begin();
            }
        }

        return ans;
    }
};

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int l = nums.size();

        long long ans = 0;

        for (int i = 0; i < l - 1; ++i) {

            multiset<int> ms;
            int tmin = nums[i];
            int tmax = nums[i];
            ms.insert(nums[i]);
            for (int j = i + 1; j < l; ++j) {
                tmin = min(tmin, nums[j]);
                tmax = max(tmax, nums[j]);

                // max - min
                ans += tmax - tmin;
            }
        }

        return ans;
    }
};



int main() {
    char c;
    Solution sol;

    vector<int> nums =  { 4, -2, -3, 4, 1 };
    cout << sol.subArrayRanges(nums);

    cin >> c;
}
