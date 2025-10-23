// easy : without memo... if add memo -> will go faster 
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
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int l = quiet.size();
        unordered_map<int, vector<int>> um;

        for (auto& it : richer) {
            um[it[1]].push_back(it[0]);
        }

        vector<int> ans(l, 0);
        //vector<vector<int>> memo(l, {-1, -1});

        for (int i = 0; i < l; ++i) {
            stack<int> st;
            vector<int> v(l, 0);
            int qmin = INT_MAX;
            int qmin_idx = -1;

            st.push(i);
            while (!st.empty()) {
                int t = st.top();
                st.pop();
                if (v[t] == 1) continue;

                if (quiet[t] < qmin) {
                    qmin = quiet[t];
                    qmin_idx = t;
                }
                v[t] = 1;
                //qmin = min(qmin, quiet[t]);
                for (auto& it : um[t]) {
                    st.push(it);
                }
            }

            //memo[t] = { qmin, qmin_idx };
            ans[i] = qmin_idx;
        }

        return ans;

    }
};

int main() {
    Solution sol;
    char c;

    vector<vector<int>> richer = {{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}};
    vector<int> quiet = {3, 2, 5, 4, 6, 1, 7, 0};

    vector<int> ans = sol.loudAndRich(richer, quiet);
    for (auto& it : ans) {
        cout << it << " ";
    }


    cin >> c;
}
