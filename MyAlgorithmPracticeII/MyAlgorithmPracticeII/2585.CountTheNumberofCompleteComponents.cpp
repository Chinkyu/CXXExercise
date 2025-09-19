// ok tricky debug and minor trim
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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<int> gm(n, 0);

        // build tree
        unordered_map<int, set<int>> em;
        for (auto& it : edges) {
            em[it[0]].insert(it[1]);
            em[it[1]].insert(it[0]);
        }

        for (int i = 0; i < n; ++i) {
            if (gm[i] == 0) {
                ans++;
                gm[i] = ans;

                vector<int> v(n, 0);
                queue<int> q;
                q.push(i);
                int edge_num = em[i].size();

                bool no_count = false;
                int cnt = 0;
                while (!q.empty()) {
                    int c = q.front();
                    q.pop();

                    v[c] = 1;
                    gm[c] = ans;
                    cnt++;
                    if (em[c].size() != edge_num) no_count = true;

                    for (auto& it : em[c]) {
                        if (v[it] == 0) {
                            q.push(it);
                            v[it] = 1;
                        }
                    }
                }

                if (no_count == true) {
                    ans--;
                }
                else if (edge_num != cnt - 1) ans--;
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> edges = { {0, 1}, {0, 2}, {1, 2}, {3, 4}/*, {3, 5}*/};

    cout << sol.countCompleteComponents(6, edges);

    cin >> c;
}