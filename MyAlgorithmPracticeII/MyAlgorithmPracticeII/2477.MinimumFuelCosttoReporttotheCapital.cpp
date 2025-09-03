//  refer answer : dfs 
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
    long long cost = 0;
    long long iterate(unordered_map<int, vector<int>>& m, int node, int from, int seat) {
        long long sub_sum = 1;

        //if (m.find(node) != m.end()) {
            for (auto& it : m[node]) {
                if (it == from) continue;
                sub_sum += iterate(m, it, node, seat);
            }
        //}

        if (node != 0) cost += ceil((double)sub_sum / seat);
        return sub_sum;
    }


    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int, vector<int>> m;
        cost = 0;

        for (auto& it : roads) {
            m[it[0]].push_back(it[1]);
            m[it[1]].push_back(it[0]);
        }

        iterate(m, 0, -1, seats);
        return cost;
    }
};

int main() {
    char c;
    Solution sol;
    string s = "1001101";

    cout << sol.maxOperations(s);

    cin >> c;
}