// 문제 이상함... 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int, int> m;
        int l = nums.size();

        for (int i = 0; i < l; ++i) {
            m[i] = nums[i];
        }

        int ans = 0;
        int ql = queries.size();
        for (int i = 0; i < ql; ++i) {
            for (int j = queries[i][0]; j <= queries[i][1]; ++j) {
                if (m.find(j) != m.end()) {
                    m[j] -= queries[i][2];
                    if (m[j] <= 0) m.erase(j);
                }
            }
            ans++;
            if (m.size() == 0) return ans;
        }

        return -1;
    }
};

int main() {
    Solution sol;
    char c;
    vector<int> tasks = { 2,2,3,3,2,4,4,4,4,4 };

    cout << sol.minimumRounds(tasks);

    cin >> c;
}
