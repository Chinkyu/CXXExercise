// ok : its signa..
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

class Solution {
public:
    long long factorialRecursive(int n) {
        if (n == 0 || n == 1) {
            return 1; // Base case: factorial of 0 or 1 is 1
        }
        else {
            return n + factorialRecursive(n - 1); // Recursive step
        }
    }

    long long countAlternatingSubarrays(vector<int>& nums) {
        int l = nums.size();

        int acc = 1;
        vector<int> n;
        for (int i = 0; i < l - 1; ++i) {
            if (nums[i] != nums[i + 1]) {
                acc++;
            }
            else {
                if (acc > 1) {
                    n.push_back(acc);
                    acc = 1;
                }
            }
        }
        if (acc > 1) {
            n.push_back(acc);
            acc = 1;
        }

        long long ans = l;
        for (auto& it : n) {
            ans += factorialRecursive(it - 1);
        }

        return ans;

    }

    long long _countAlternatingSubarrays(vector<int>& nums) {
        long long res = 1, size = 1;
        for (int i = 1; i < nums.size(); ++i) {
            size = nums[i - 1] == nums[i] ? 1 : size + 1;
            res += size;
        }
        return res;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> nums = { 1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1 };

    cout << sol.countAlternatingSubarrays(nums);

    cin >> c;
}