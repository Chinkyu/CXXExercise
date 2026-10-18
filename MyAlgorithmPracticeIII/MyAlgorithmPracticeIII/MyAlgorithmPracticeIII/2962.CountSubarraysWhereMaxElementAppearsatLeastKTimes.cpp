// Ok :내계산이 맞는것 같음.... 
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

class Solution {
public:
    bool isKthInMap(unordered_map<int, int>& m, int k) {

        int tmax = 0;
        for (auto& it : m) {
            if (it.second >= k) {
                return true;
            }
        }

        return false;
    }


    long long countSubarrays1(vector<int>& nums, int k) {
        int l = nums.size();
        unordered_map<int, int> m;

        int st = 0;
        long long ans = 0;
        m[nums[0]]++;
        for (int i = st; i < l;) {
            if (isKthInMap(m, k)) {
                ans += l - i;
                m[nums[st]]--;
                st++;
                continue;
            }
            i++;
            if(i < l) m[nums[i]]++;
        }

        return ans;
    }

    long long countSubarrays(vector<int>& nums, int k) {
        int l = nums.size();
        unordered_map<int, int> m;

        int st = 0;
        long long ans = 0;
        m[nums[0]]++;
        for (int i = 0; i < l; ++i) {
            m.clear();
            for (int j = i; j < l; ++j) {
                m[nums[j]]++;
                if (isKthInMap(m, k)) {
                    ans += l - j;
                    break;
                }
            }
        }

        return ans;
    }

};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 61,23,38,23,56,40,82,56,82,82,82,70,8,69,8,7,19,14,58,42,82,10,82,78,15,82 };

    cout << sol.countSubarrays(nums, 2);

    cin >> c;
}
