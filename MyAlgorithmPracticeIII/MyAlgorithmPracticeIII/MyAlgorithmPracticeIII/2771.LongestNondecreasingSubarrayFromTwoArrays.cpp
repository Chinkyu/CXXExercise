// dp.. 
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
    int maxNonDecreasingLength(vector<int>& u, vector<int>& v)
    {
        int n = u.size(), ans = 1, uc = 1, vc = 1;

        for (int i = 1; i < n; i++)
        {
            int l = 1, r = 1;
            if (u[i] >= u[i - 1]) l = uc + 1;
            if (u[i] >= v[i - 1]) r = vc + 1;

            int l2 = 1, r2 = 1;
            if (v[i] >= u[i - 1]) l2 = uc + 1;
            if (v[i] >= v[i - 1]) r2 = vc + 1;

            uc = max(l, r);
            vc = max(l2, r2);
            ans = max({ ans,uc,vc });
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,0,-1,0,-2,2 };

    vector<vector<int>> ans = sol.fourSum(nums, 0);

    for (auto& it : ans) {
        cout << it[0] << "," << it[1] << "," << it[2] << "." << it[3];
    }


    cin >> c;
}
