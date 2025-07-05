// 답보고 참조해서 고쳤음.  gcd 는 어려움  그런데  __gcd 가 Gcc 에는 있나 보다... 
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
#include <iostream>

using namespace std;

class Solution {
public:

    long long gcd(long long int a, long long int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long long lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }

    int subarrayLCM(vector<int>& nums, int k) {
        int cnt = 0;
        int l = nums.size();

        for (int i = 0; i < l; i++) {
            int t_lcm = nums[i];
            //if (t_lcm == k) cnt++;  // ist k itself

            for (int j = i; j < l; j++)
            {
                t_lcm = lcm(t_lcm, nums[j]);

                if (t_lcm == k) {
                    cnt++;
                }
                if (t_lcm > k) break;
            }
        }
        return cnt;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums { 3, 6, 2, 7, 1};

    cout << sol.subarrayLCM(nums, 6);

    cin >> c;
}
