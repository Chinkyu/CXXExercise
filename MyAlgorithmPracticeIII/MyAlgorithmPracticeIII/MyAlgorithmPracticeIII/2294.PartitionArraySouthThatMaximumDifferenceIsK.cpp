// easy : by sorting and chunking 
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

using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int l = nums.size();

        sort(nums.begin(), nums.end());

        int ans = 0;
        int st = nums[0];
        for (int i = 1; i < l; ++i) {
            if (nums[i] - st > k) {
                ans++;
                st = nums[i];
            }
        }

        ans++;

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> 
    cout << sol.largestMerge(word1, word2);


    cin >> c;
}
