// see answer : hamming distance 구하는게 생각보다 쉽네.  a ^ b   -> __biltin_popcount()  
//   
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
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int xOR = nums[i] ^ nums[j];
                ans += __builtin_popcount(xOR);
            }
        }
        return ans;
    }
};

int main() {
    char c;
    Solution sol;


    vector<string> ans = sol.simplifiedFractions(4);

    for (auto& it : ans) {
        cout << it << " ";
    }


    cin >> c;
}
