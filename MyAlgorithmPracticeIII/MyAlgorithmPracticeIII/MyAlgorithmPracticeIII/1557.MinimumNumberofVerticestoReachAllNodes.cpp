// ok : find parents 
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
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        // identify parents 
        map<int, vector<int>> p;

        for (auto& it : edges) {
            p[it[1]].push_back(it[0]);
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (p.find(i) == p.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> buildings = {{0, 1}, {2, 1}, {3, 1}, {1, 4}, {2,4}};

    vector<int> ans = sol.findSmallestSetOfVertices( 5, buildings);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
