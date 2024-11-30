//  ¥‰∫√¿Ω :  There is esay solution...........!!!! my god... 
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
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] == 0) {
                k--;
            }
            if (k < 0) {
                if (nums[i] == 0) {
                    k++;
                }
                i++;
            }
            j++;
        }
        return j - i;
    }
};

// timeout 
class _Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = nums.size();
        vector<int> v(l, 0);



        int c = 0;
        for (int i = 0; i < l; ++i) {
            if (nums[i] == 0) v[i] = ++c;
            else v[i] = c;
        }
        v.push_back(c + 1);

        int ans = 0;
        if (k == 0) {  // find longest 1
            int mone = 0;
            for (int i = 0; i < l; ++i) {
                if (nums[i] == 0) {
                    ans = max(ans, mone);
                    mone = 0;
                }
                else {
                    mone++;
                }
            }
            ans = max(ans, mone);
        }
        else {
            for (int i = 0; i < l; ++i) {
                for (int j = i + 1; j <= l; ++j) {
                    int b = (i - 1 < 0) ? 0 : v[i - 1];

                    if (i == 0 && j == l && v[j] - b <= k) {
                        ans = max(ans, l);
                        break;
                    }

                    if (v[j] - b <= k) continue;
                    ans = max(ans, j - i);

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

    vector<int> nums = { 1,1,1,0,0,0,1,1,1,1 }; // { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };

    cout << sol.longestOnes(nums, 0);

    cin >> c;
}