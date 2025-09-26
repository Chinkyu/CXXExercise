// ok : tricky when input doesn't comes continuously 
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
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, int> p;
        unordered_map<int, vector<int>> e;

        for (auto& it : edges) {
            e[it[0]].push_back(it[1]);
            e[it[1]].push_back(it[0]);
        }

        stack<int> st;
        st.push(0);
        p[0] = 0;

        while (st.size() != 0) {
            int c = st.top();
            st.pop();

            for (auto& it : e[c]) {
                if (it == p[c]) continue;
                p[it] = c;
                st.push(it);
            }
        }


        set<int> app;
        for (int i = 1; i < n; ++i) {
            if (hasApple[i] == true) {
                app.insert(i);
                int c = i;
                while (p[c] != 0) {
                    app.insert(p[c]);
                    c = p[c];
                }
            }
        }

        return app.size() * 2;
    }
};

int main() {
    Solution sol;
    char c;

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
    vector<bool> hasApple = { false,false,true,false,false,true,false };

    cout << sol.minTime(6, edges, hasApple);

    cin >> c;
}
