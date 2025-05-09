//  ok
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
#include <set>
#include <list>
#include <regex>
#include <memory>
#include <functional>

using namespace std;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> um;

        for (auto it: access_times) {
            int t = stoi(it[1]);
            um[it[0]].push_back(t);
        }

        vector<string> ans;
        for (auto it : um) {
            vector<int> v = it.second;

            sort(v.begin(), v.end());
            if (v.size() < 3) continue;
            for (int i = 0; i <= v.size() - 3; ++i) {
                if (v[i + 2] - v[i] < 100) {
                    ans.push_back(it.first);
                    break;
                }
            }

        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<string>> access_times = {{"a", "0549"}, {"b", "0457"}, {"a", "0532"}, {"a", "0621"}, {"b", "0540"}};

    vector<string> ans =  sol.findHighAccessEmployees(access_times);

    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}