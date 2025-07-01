// ok : 기존답 봤고... 변형해서 더 간단하게 ... exception case tricky
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


// Accumulation 하면서 나머지를 구해서 나머지가 같은것이 나오면 Bingo
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int l = nums.size();
        map<int, int> remain;

        if (l <= 1) return false;

        // handle zero exist
        remain[0] = -1;

        int mod = 0;
        for (int i = 0; i < l; ++i) {
            mod = (mod + nums[i]) % k;

            if (remain.find(mod) != remain.end()) {
                if(i - remain[mod] >= 2) return true;
            }
            else {
                // record only first one 
                remain[mod] = i;
            }
        }

        return false;

    }
};


// timeout
class _Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int l = nums.size();
        vector<int> ac(l+1, 0);

        if (l <= 1) return false;

        ac[0] = 0;
        for (int i = 1; i < l+1; ++i) {
            ac[i] = (ac[i - 1] + nums[i-1]) % k;
        }

        //for (int i = 0; i < l-1; ++i) {
        for (int i = l-2; 0 <= i; --i) {
            for (int j = i + 2; j < l+1; ++j) {
                int sub_sum = ac[j] - ac[i];

                if (sub_sum % k == 0) return true;
            }
        }

        return false;
    }
};

int main() {
    char c;
    Solution sol;

    //vector<int> nums = { 23, 2, 4, 6, 7 };
    //vector<int> nums = { 23,2,6,4,7 };
    //vector<int> nums = { 1, 0 };
    vector<int> nums = { 23,2,4, 6, 6 };

    cout << sol.checkSubarraySum(nums, 7);

    cin >> c;
}