// 

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
    int ans = 0;
    int traverse(unordered_map<int, vector<int>>& m, int root) {

        if (m.find(root) == m.end()) {
            cout << root << " ";
            ans++;
            return 1;
        }

        int fc = traverse(m, m[root][0]);
        int sum = fc;
        bool all_same = true;
        for (int i = 1; i < m[root].size(); ++i) {
            int nc = traverse(m, m[root][i]);
            if (fc != nc) all_same = false;
            sum += nc;
        }
        

        if (all_same) {
            cout << root << " ";
            ans++;
        }
        return sum + 1;

    }


    int countGoodNodes(vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> m;

        for (auto& it : edges) {
            m[it[0]].push_back(it[1]);
        }

        ans = 0;
        traverse(m, 0);
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<vector<int>> edges = { {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6} };
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {1, 4}, {0, 5}, {5, 6}, {6, 7}, {7, 8}, {0, 9}, {9, 10}, {9, 12}, {10, 11}};

    cout << sol.countGoodNodes(edges);

    cin >> c;
}