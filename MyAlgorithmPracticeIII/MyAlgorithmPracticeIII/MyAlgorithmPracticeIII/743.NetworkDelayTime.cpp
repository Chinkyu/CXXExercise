// see answer : dijkstra 
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
    void display1(const vector<int>& v) {
        for (int i = 1; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    int networkDelayTime(vector<vector<int>>& tms, int n, int k) {
        vector<vector<int>> edge(n + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 0; i < tms.size(); i++)
        {
            int start = tms[i][0], end = tms[i][1], value = tms[i][2];
            edge[start][end] = min(edge[start][end], value);
        }

        vector<int> table(n + 1, 10000);
        table[k] = 0;
        table[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_queue;

        min_queue.push(make_pair(0, k));


        while (!min_queue.empty()) {

            auto it = min_queue.top();
            min_queue.pop();
            int cur = it.second;
            int cur_val = it.first;
            if (cur_val > table[cur]) continue;

            vector<int> temp = edge[cur];

            for (int i = 1; i < temp.size(); i++)
            {
                if (temp[i] < INT_MAX && cur_val + temp[i] < table[i]) {
                    table[i] = cur_val + temp[i];
                    min_queue.push({ table[i], i });
                }

            }

        }
        display1(table);
        int ans = 0;
        for (int i = 1; i < table.size(); i++)
        {
            if (i == k)    continue;
            ans = max(ans, table[i]);
        }
        return ans == 10000 ? -1 : ans;
    }
};

int main() {
    char c;
    vector<vector<int>> tasks = { {1, 101, 10},{2, 102, 20},{3, 103, 15 } };

    TaskManager sol(tasks);

    sol.add(4, 104, 5);
    sol.edit(102, 8);
    cout << sol.execTop();

    cin >> c;
}
