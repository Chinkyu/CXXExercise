// see answer : prune to answer till there is no terminal node 
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
    vector<int> eventualSafeNodes(vector<vector<int>>& G) {
        int N = G.size();
        vector<vector<int>> R(N);
        vector<int> outdegree(N), safe(N), ans;
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            for (int v : G[i]) {
                R[v].push_back(i);
            }
            outdegree[i] = G[i].size();
            if (outdegree[i] == 0) q.push(i);
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            safe[u] = 1;
            for (int v : R[u]) {
                if (--outdegree[v] == 0) q.push(v);
            }
        }
        for (int i = 0; i < N; ++i) {
            if (safe[i]) ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    char c;
    Solution sol;


    vector<string> ans = sol.simplifiedFractions(4);

    for (auto& it : ans) {
        cout << it << " ";
    }


    cin >> c;
}
