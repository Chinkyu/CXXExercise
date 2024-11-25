//  easy : two late..  may have more improvement
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
#include <functional>

using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int l = values.size();
        vector<vector<int>> cv(30000);

        for (int i = 0; i < 30000; ++i) {
            cv[labels[i]].push_back(values[i]);
        }

        vector<int> v;
        for (int i = 0; i < l; ++i) {
            if (cv[i].size() == 0) continue;
            sort(cv[i].begin(), cv[i].end(), std::greater<int>());

            for (int j = 0; j < cv[i].size() && j < useLimit; ++j) {
                v.push_back(cv[i][j]);
            }
        }

        sort(v.begin(), v.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < numWanted && i < v.size(); ++i)  ans += v[i];

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> values = { 9 }; // { 5, 4, 3, 2, 1 };
    vector<int> labels = { 2 }; // { 1, 1, 2, 2, 3 };

    cout << sol.largestValsFromLabels(values, labels, 1, 1);

    cin >> c;
}