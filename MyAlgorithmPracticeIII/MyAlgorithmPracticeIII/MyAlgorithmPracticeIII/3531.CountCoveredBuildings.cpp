// ok : row, column  with map  low and high 
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
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int, vector<int>> rm, cm;

        for (auto& it : buildings) {
            // row
            int sz = rm[it[0]].size();
            if (sz == 0) {
                rm[it[0]].push_back(it[1]);
            }
            else if (sz == 1) {
                rm[it[0]].push_back(it[1]);
                if (rm[it[0]][0] > rm[it[0]][1]) {
                    swap(rm[it[0]][0], rm[it[0]][1]);
                }
            }
            else {
                if (it[1] < rm[it[0]][0]) rm[it[0]][0] = it[1];
                if (rm[it[0]][1] < it[1]) rm[it[0]][1] = it[1];
            }

            // column
            sz = cm[it[1]].size();
            if (sz == 0) {
                cm[it[1]].push_back(it[0]);
            }
            else if (sz == 1) {
                cm[it[1]].push_back(it[0]);
                if (cm[it[1]][0] > cm[it[1]][1]) {
                    swap(cm[it[1]][0], cm[it[1]][1]);
                }
            }
            else {
                if (it[0] < cm[it[1]][0]) cm[it[1]][0] = it[0];
                if (cm[it[1]][1] < it[0]) cm[it[1]][1] = it[0];
            }
        }

        // count 
        int ans = 0;
        for (auto& it : buildings) {
            if (rm[it[0]].size() == 2 && rm[it[0]][0] < it[1] && it[1] < rm[it[0]][1] &&
                cm[it[1]].size() == 2 && cm[it[1]][0] < it[0] && it[0] < cm[it[1]][1]) {
                ans++;
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<vector<int>> buildings = {{1, 3}, {3, 2}, {3, 3}, {3, 5}, {5, 3}};
    vector<vector<int>> buildings = {{2, 4}, {1, 2}, {3, 1}, {1, 4}, {2, 3}, {3, 3}, {2, 2}, {1, 3}};

    cout << sol.countCoveredBuildings(4, buildings);

    cin >> c;
}
