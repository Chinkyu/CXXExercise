// easy using map
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < numbers.size(); ++i) {
            m[numbers[i]] = i;
        }


        vector<int> ans(2, 0);
        for (int i = 0; i < numbers.size(); ++i) {
            if (m.find(target - numbers[i]) != m.end()) {
                ans[0] = i + 1;
                ans[1] = m[target - numbers[i]] + 1;
                return ans;
            }
        }
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> numbers = { 2, 7, 11, 15 };

    vector<int> ans = sol.twoSum(numbers, 9);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
