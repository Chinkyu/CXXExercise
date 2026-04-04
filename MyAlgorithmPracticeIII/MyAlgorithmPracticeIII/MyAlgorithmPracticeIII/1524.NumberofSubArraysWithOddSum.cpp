// see answer
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


//  대단한 알로리즘이다..
// 끝을 기준으로 prefixsum 에 따라 앞에서 격었던 Evensum, odd sum 을 가지고 앞에서 여기까지  Subarray 의 합이
// even odd 인지를 확인해서 개수를 찾는 방법
// one loop 로 해결 되네....  

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int count = 0, prefixSum = 0;
        // evenCount starts as 1 since the initial sum (0) is even
        int oddCount = 0, evenCount = 1;

        for (int num : arr) {
            prefixSum += num;
            // If current prefix sum is even, add the number of odd subarrays
            if (prefixSum % 2 == 0) {
                count += oddCount;
                evenCount++;
            }
            else {
                // If current prefix sum is odd, add the number of even
                // subarrays
                count += evenCount;
                oddCount++;
            }

            count %= MOD;  // To handle large results
        }

        return count;
    }
};



// timeout 
class _Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        int count = 0;

        vector<int> accu(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            arr[i] &= 1;
            accu[i + 1] = accu[i] ^ arr[i];
        }


        for (int i = 0; i < accu.size() - 1; ++i) {
            for (int j = i + 1; j < accu.size(); ++j) {
                if ((accu[i] ^ accu[j]) == 1) {
                    count++;
                    count %= MOD;
                }
            }
        }

        return count % MOD;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> arr = { 1, 3, 5 };

    cout << sol.numOfSubarrays(arr);

    cin >> c;
}
