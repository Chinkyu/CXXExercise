// ok : low performace with  traverse with map

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
#include <random>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int l = quiet.size();
        unordered_map<int, vector<int>> ri;

        for (auto& it : richer) {
            ri[it[1]].push_back(it[0]);
        }

        vector<int> ans(l, 0);
        for (int i = 0; i < l; ++i) {
            queue<int> q;
            int min_idx = i, min_val = quiet[i];  // if no, itself


            q.push(i);
            while (!q.empty()) {
                queue<int> tq;
                vector<int> v(l, 0);

                while (!q.empty()) {
                    int c = q.front();
                    q.pop();
                    for (auto& it : ri[c]) {
                        if (v[it] != 1) {
                            tq.push(it);
                            v[it] = 1;

                            if (quiet[it] < min_val) {
                                min_val = quiet[it];
                                min_idx = it;
                            }
                        }
                    }
                }
                q = tq;
            }

            ans[i] = min_idx;
        }

        return ans;
    }
};


int main() {
    char c;
    Solution sol;

    vector<vector<int>> richer = {{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}};
    vector<int> quiet = {3, 2, 5, 4, 6, 1, 7, 0};

    vector<int> ans =  sol.loudAndRich(richer, quiet);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
