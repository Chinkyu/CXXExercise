// see answer
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

//  이렇게 해도 된다네...... 진짜...
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, const int T) {
        unordered_set<int> prefixes;
        prefixes.emplace(0);

        int sum = 0, ret = 0;
        for (const int n : nums) {
            sum += n;
            if (prefixes.count(sum - T)) {
                ret += 1;
                sum = 0;
                prefixes.clear();
            }
            prefixes.emplace(sum);
        }
        return ret;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> edges = { {1, 0}, {1, 2}, {1, 3} };
    //"baeyh";

    vector<int> ans = sol.findMinHeightTrees(4, edges);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
