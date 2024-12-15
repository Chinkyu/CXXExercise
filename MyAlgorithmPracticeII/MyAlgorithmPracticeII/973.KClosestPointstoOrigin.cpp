// easy : using multimap
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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<float, int> mm;

        for (int i = 0; i < points.size(); ++i) {
            float d = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));

            mm.insert({ d, i });
        }

        vector<vector<int>> ans;
        int idx = 0;
        for (auto &it : mm) {
            ans.push_back({ points[it.second][0], points[it.second][1]});
            if (++idx >= k) break;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};

    vector<vector<int>> ans =  sol.kClosest(points, 2);

    for (auto& it : ans) {
        cout << it[0] << " " << it[1] << endl;
    }

    cin >> c;
}