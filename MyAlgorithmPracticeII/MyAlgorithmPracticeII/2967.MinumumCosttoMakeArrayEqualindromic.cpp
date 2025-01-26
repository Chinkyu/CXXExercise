//  답참조함 : minimum distance 가 mean 이 아니라 Median 이라는점... !!!1 
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
#include <functional>

using namespace std;


// wrong answer
class _Solution {
public:

    bool checkPalindrome(int n) {
        int reverse = 0;

        // Copy of the original number so that the original
        // number remains unchanged while finding the reverse
        int temp = n;
        while (temp != 0) {
            reverse = (reverse * 10) + (temp % 10);
            temp = temp / 10;
        }

        // If reverse is equal to the original number, the
        // number is palindrome
        return (reverse == n);
    }

    long long distance(vector<int>& nums, int a) {
        long long d = 0;

        for (auto& it : nums) {
            d += abs(it - a);
        }

        return d;
    }

    long long minimumCost(vector<int>& nums) {
        int l = nums.size();
        long long sum = 0;

        for (auto& it : nums) sum += it;
        int avg = sum / l;

        long long d = LLONG_MAX;
        if (checkPalindrome(avg)) {
            d = distance(nums, avg);
        }

        if (checkPalindrome(avg - 1)) {
            d = min(d, distance(nums, avg - 1));
        }

        if (checkPalindrome(avg + 1)) {
            d = min(d, distance(nums, avg + 1));
        }
        if (d != LLONG_MAX) return d;

        int i = 2;

        while (i <= 20) {
            long long d = LLONG_MAX;
            if (checkPalindrome(avg - i)) {
                d = distance(nums, avg - i);
            }

            if (checkPalindrome(avg + i)) {
                d = min(d, distance(nums, avg + i));
            }
            if (d != LLONG_MAX) return d;
            i++;
        }

        return -1;
    }
};




class Solution {
public:

    bool checkPalindrome(int n) {
        int reverse = 0;

        // Copy of the original number so that the original
        // number remains unchanged while finding the reverse
        int temp = n;
        while (temp != 0) {
            reverse = (reverse * 10) + (temp % 10);
            temp = temp / 10;
        }

        // If reverse is equal to the original number, the
        // number is palindrome
        return (reverse == n);
    }

    long long distance(vector<int>& nums, int a) {
        long long d = 0;

        for (auto& it : nums) {
            d += abs(it - a);
        }

        return d;
    }

    long long minimumCost(vector<int>& nums) {
        int l = nums.size();
        long long sum = 0;

        sort(nums.begin(), nums.end());

        int med = l / 2;

        int lx = med;
        while (!checkPalindrome(nums[lx])) {
            lx--;
        }

        int rx = med;
        while (!checkPalindrome(nums[rx])) {
            rx++;
        }

        return min(distance(nums, nums[lx]), distance(nums, nums[rx]));
    }
};



int main() {
    char c;
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5 };

    cout << sol.minimumCost(nums);


    cin >> c;
}