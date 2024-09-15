// 간단한 문제가 아님 : knapsack..... !!  다 해봐야함.. 
// bitmap 을 가지고 모든수를 더하는 방법은 기억하면 좋을것 같다.. 
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

class Solution {  // magical solution 
public:
    bool canPartition(vector<int>& nums) {
        const int MAX_NUM = 100;
        const int MAX_ARRAY_SIZE = 200;
        bitset<MAX_NUM* MAX_ARRAY_SIZE / 2 + 1> bits(1);
        int sum = 0;
        for (auto n : nums) {
            sum += n;
            bits |= bits << n;
        }
        return !(sum % 2) && bits[sum / 2];
    }
};

// not workin from both side
class _Solution {
public:
    bool canPartition(vector<int>& nums) {
        int l = nums.size();

        if (l <= 1) return false;

        sort(nums.begin(), nums.end());

        int li = 0, ri = l - 1;
        int lsum = 0, rsum = 0;

        do {
            rsum += nums[ri--];

            while (li <= ri && lsum + nums[li] <= rsum) lsum += nums[li++];
        } while (li <= ri);

        if (lsum == rsum) return true;
        return false;
    }
};

// put this in small sum from back 
class __Solution {
public:
    bool canPartition(vector<int>& nums) {
        int l = nums.size();

        if (l <= 1) return false;

        sort(nums.begin(), nums.end());

        int li = 0, ri = l - 1;
        int lsum = 0, rsum = 0;
    
        rsum = nums[l - 1];
        for (int i = l - 2; i >= 0; --i) {
            if (lsum <= rsum) {
                lsum += nums[i];
            }
            else {
                rsum += nums[i];
            }
        }

        if (lsum == rsum) return true;
        return false;
    }
};

// find both way -> 이것도 해결책이 안됨. 
class ___Solution {
public:
    bool canPartition_internal1(vector<int>& nums) {
        int l = nums.size();

        if (l <= 1) return false;

        sort(nums.begin(), nums.end());

        int li = 0, ri = l - 1;
        int lsum = 0, rsum = 0;

        do {
            rsum += nums[ri--];

            while (li <= ri && lsum + nums[li] <= rsum) lsum += nums[li++];
        } while (li <= ri);

        if (lsum == rsum) return true;
        return false;
    }

    bool canPartition_internal2(vector<int>& nums) {
        int l = nums.size();

        if (l <= 1) return false;

        sort(nums.begin(), nums.end());

        int li = 0, ri = l - 1;
        int lsum = 0, rsum = 0;

        rsum = nums[l - 1];
        for (int i = l - 2; i >= 0; --i) {
            if (lsum <= rsum) {
                lsum += nums[i];
            }
            else {
                rsum += nums[i];
            }
        }

        if (lsum == rsum) return true;
        return false;
    }

    bool canPartition(vector<int>& nums) {
        bool ans = false;

        return  canPartition_internal1(nums) | canPartition_internal2(nums);
    }
};

int main() {
    Solution sol;
    char c;

    vector<int> nums = { 3, 3, 3, 4, 5 };
    //vector<int> nums = { 1, 3, 4, 4 };
    //vector<int> nums = { 2, 2, 1, 1 };

    cout << sol.canPartition(nums);

    cin >> c;
}
