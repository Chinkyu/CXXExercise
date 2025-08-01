// ok : see hint great
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <cmath>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {

        map<int, vector<int>> m;

        // x coord
        for (auto& it : coords) {
            m[it[0]].push_back(it[1]);
        }

        long long ans = -1;
        int st = m.begin()->first;
        int end = m.rbegin()->first;
        for (auto& it : m) {
            if (it.second.size() > 1) {
                vector<int> v = it.second;
                sort(v.begin(), v.end());
                int delta = v.back() - v[0];
                ans = max(ans, ((long long)delta * (it.first - st)));
                ans = max(ans, ((long long)delta * (end - it.first)));
            }
        }

        // y coord
        m.clear();
        for (auto& it : coords) {
            m[it[1]].push_back(it[0]);
        }

        st = m.begin()->first;
        end = m.rbegin()->first;
        for (auto& it : m) {
            if (it.second.size() > 1) {
                vector<int> v = it.second;
                sort(v.begin(), v.end());
                int delta = v.back() - v[0];
                ans = max(ans, ((long long)delta * (it.first - st)));
                ans = max(ans, ((long long)delta * (end - it.first)));
            }
        }
        
        if (ans == 0) ans = -1;
        return ans;
    }
};


int main() {
    char c;
    Solution sol;
    vector<vector<int>> coords = {{1, 1}, {1, 2}, {3, 2}, {3, 3}};

    std::cout << sol.maxArea(coords);
    std::cin >> c;
}