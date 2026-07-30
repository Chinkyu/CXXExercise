// ok : use stack like vector
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
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;

        for (int i = 0; i < nums.size(); ++i) {
            ans.push_back(nums[i]);
            while (ans.size() >= 2 && (ans[ans.size() - 1] == ans[ans.size() - 2])) {
                long sum = ans[ans.size() - 1];
                ans.pop_back();
                sum += ans[ans.size() - 1];
                ans.pop_back();
                ans.push_back(sum);
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 3, 1, 1, 2 };

    vector<long long> ans = sol.mergeAdjacent(nums);

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }

    cin >> c;
}
