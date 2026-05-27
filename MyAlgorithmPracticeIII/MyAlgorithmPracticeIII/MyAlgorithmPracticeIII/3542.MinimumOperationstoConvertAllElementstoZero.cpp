// see answer : nonotonic stack 
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
#include <bit>

using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> s;
        int res = 0;
        for (int a : nums) {
            while (!s.empty() && s.back() > a) {
                s.pop_back();
            }
            if (a == 0) continue;
            if (s.empty() || s.back() < a) {
                ++res;
                s.push_back(a);
            }
        }
        return res;
    }
};

// timeout for long long data 
class Solution {
public:
    int ToZero(vector<int>& nums, int st, int ed) {
        if (st == ed) return 1;

        set<int> s;
        int ans = 1;

        // find min
        for (int i = st; i <= ed; ++i) {
            s.insert(nums[i]);
        }
        int tmin = *s.begin();

        // identify non zero chunk from st, to ed 
        int tst = st, ted = st;
        for (int i = st; i <= ed; ++i) {
            if (nums[i] == tmin) {
                ted = i - 1;
                if (ted - tst >= 0) {
                    ans += ToZero(nums, tst, ted);
                }
                tst = i + 1;
            }
        }
        ted = ed;
        if (ted - tst >= 0) {
            ans += ToZero(nums, tst, ted);
        }

        return ans;
    }

    int minOperations(vector<int>& nums) {
        int l = nums.size();

        int ans = 0;
        int st = 0, ed = l - 1;
        for (int i = st; i <= l - 1; ++i) {
            if (nums[i] == 0) {
                ed = i - 1;
                if (ed - st >= 0) {
                    ans += ToZero(nums, st, ed);
                }
                st = i + 1;
            }
        }
        ed = l - 1;
        if (ed - st >= 0) {
            ans += ToZero(nums, st, ed);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 6, 0, 0, 0 };
    //{ 1,2,1,2,1,2 };

    cout << sol.minOperations(nums);

    cin >> c;
}

