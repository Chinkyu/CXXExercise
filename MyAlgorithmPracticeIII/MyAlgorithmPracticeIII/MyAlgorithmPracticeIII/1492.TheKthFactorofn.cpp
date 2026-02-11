// Really not timeout 
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
    int kthFactor(int n, int k) {

        int cnt = 0;

        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                cnt++;
                if (cnt == k) {
                    return i;
                }
            }
        }

        return -1;
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
