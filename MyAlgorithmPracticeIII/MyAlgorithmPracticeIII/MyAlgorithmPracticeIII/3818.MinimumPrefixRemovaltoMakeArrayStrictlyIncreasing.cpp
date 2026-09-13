// ok : check from back 
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
    int minimumPrefixLength(vector<int>& nums) {
        int l = nums.size();
        vector<int> d;

        int cnt = 1;
        for (int i = l - 1; i >= 1; --i) {
            if (nums[i - 1] >= nums[i]) {
                break;
            }
            cnt++;
        }

        return l - cnt;

    }
};

int main() {
    char c;
    Solution sol;

    string s = "1101";
    cout << sol.numSteps(s);

    cin >> c;
}
