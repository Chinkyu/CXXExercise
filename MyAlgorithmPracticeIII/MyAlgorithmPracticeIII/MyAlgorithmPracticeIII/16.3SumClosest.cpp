// see answer...  choose 1 and adjust low and high to find nearest
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
#include <chrono>
#include <iterator>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (abs(target - sum) < abs(target - result))
                    result = sum;

                if (sum == target) return target;
                else if (sum < target) left++;
                else right--;
            }
        }

        return result;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "au";
    //"abcabcbb";

    cout << sol.lengthOfLongestSubstring(s);

    cin >> c;
}
