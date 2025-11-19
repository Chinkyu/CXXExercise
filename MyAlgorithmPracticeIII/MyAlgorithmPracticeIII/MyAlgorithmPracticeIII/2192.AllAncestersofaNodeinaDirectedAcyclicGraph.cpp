// ok : reverse edge and visit list  use set 
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
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> father(n, vector<int>());

        for (auto& it : edges) {
            father[it[1]].push_back(it[0]);  // make edge reversely 
        }

        vector<vector<int>> ans(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            set<int> s;
            vector<int> v(n, 0);

            stack<int> st;
            st.push(i);

            while (!st.empty()) {
                int c = st.top();
                st.pop();
                if (v[c] == 1) continue;

                v[c] = 1;

                for (auto& it : father[c]) {
                    s.insert(it);
                    st.push(it);
                }
            }

            for (auto& it : s) {
                ans[i].push_back(it);
            }
        }

        return ans;

    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> edgeList = { {0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6} };

    //cout << sol.exchange(s, 5);
    vector<vector<int>> ans = sol.getAncestors(8, edgeList);

    for (auto& it : ans) {
        for (auto& jt : it) {
            cout << jt << " ";
        }
        cout << endl;
    }

    cin >> c;
}
