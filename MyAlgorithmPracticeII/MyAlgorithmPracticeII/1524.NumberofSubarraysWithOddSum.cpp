//  ¥‰∫√¿Ω : timeout - sliding window with n number 
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
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        int count = 0;

        // Generate all possible subarrays
        for (int startIndex = 0; startIndex < n; startIndex++) {
            int currentSum = 0;
            // Iterate through each subarray starting at startIndex
            for (int endIndex = startIndex; endIndex < n; endIndex++) {
                currentSum += arr[endIndex];
                // Check if the sum is odd
                if (currentSum % 2 != 0) {
                    count++;
                }
            }
        }

        return count % MOD;
    }
};

// timeout
class _Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int> na;
        for (auto it : arr) {
            if (it % 2 == 0) {
                na.push_back(0);
            }
            else {
                na.push_back(1);
            }
        }

        int ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            int o = 0;
            for (int j = i; j < arr.size(); ++j) {
                o ^= na[j];
                if (o == 1) {
                    ans++;
                    ans %= 1000000007;
                }
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> arr = { 1, 3, 5 };


    cout << sol.numOfSubarrays(arr);

    cin >> c;
}