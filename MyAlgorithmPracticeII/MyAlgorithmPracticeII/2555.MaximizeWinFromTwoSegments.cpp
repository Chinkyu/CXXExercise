// see answer : dp

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


// Serial check => Timeout 
class _Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int l = prizePositions.size();
        map<int, int> m;

        for (auto& it : prizePositions) {
            m[it]++;
        }

        int ls = 0, rs = 0;
        int ans = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {

            auto ite = it;
            ls = 0;
            while (ite != m.end() && ite->first <= it->first + k) {
                ls += ite->second;
                ite++;
            }

            for (auto jt = ite; jt != m.end(); ++jt) {
                auto jte = jt;

                rs = 0;
                while (jte != m.end() && jte->first <= jt->first + k) {
                    rs += jte->second;
                    jte++;
                }

                ans = max(ans, ls + rs);
                if (ans == l) return l;
            }

            ans = max(ans, ls + rs);
            if (ans == l) return l;
        }
        
        return ans;
    }
};

class Solution
{
public:
    int maximizeWin(vector<int>& nums, int k)
    {
        int n = nums.size(), start = 0, ans = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            while (nums[i] - nums[start] > k)
                start++;

            ans = max(ans, i - start + 1 + (start > 0 ? dp[start - 1] : 0));
            dp[i] = max((i > 0 ? dp[i - 1] : 0), i - start + 1);
        }
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> prizePositions = { 2616,2618,2620,2621,2626,2635,2657,2662,2662,2669,2671,2693,2702,2713,2714,2718,2730,2731,2750,2756,2772,2773,2775,2785,2795,2805,2811,2813,2816,2823,2824,2824,2826,2830,2833,2857,2885,2898,2910,2919,2928,2941,2942,2944,2965,2967,2970,2973,2974,2975,2977,3002,3007,3012,3042,3049,3078,3084,3089,3090,3094,3097,3114,3124,3125,3125,3144,3147,3148,3174,3197,3255,3262,3288,3291,3316,3320,3322,3331,3342,3378,3412,3412,3416,3420,3427,3428,3446,3452,3472,3479,3483,3488,3500,3516,3522,3531,3532,3540,3540,3544,3557,3570,3580,3592,3597,3597,3601,3615,3631,3640,3645,3673,3677,3681,3683,3685,3718,3738,3746,3758,3769,3797,3802,3815,3832,3839,3851,3864,3888,3889,3901,3902,3910,3913,3933,3940,3961,3974,3988,4003,4013,4019,4023,4026,4047,4060,4065,4072,4073,4082,4084,4109,4132,4139,4143,4145,4146,4155 };

    cout << sol.maximizeWin(prizePositions, 6641);

    cin >> c;
}