// see answer : due to memory limit
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

class _Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {

        vector<int> g(c + 1, 0);

        // build tree
        unordered_map<int, set<int>> em;
        for (auto& it : connections) {
            em[it[0]].insert(it[1]);
            em[it[1]].insert(it[0]);
        }

        int group = 0;
        for (int i = 1; i <= c; ++i) {
            if (g[i] == 0) {
                group++;
                g[i] = group;

                vector<int> v(c+1, 0);
                queue<int> q;
                q.push(i);
                int cnt = 0;
                while (!q.empty()) {
                    int c = q.front();
                    q.pop();

                    v[c] = 1;
                    g[c] = group;
                    for (auto& it : em[c]) {
                        if (v[it] == 0) {
                            q.push(it);
                            v[it] = 1;
                        }
                    }
                }


            }
        }

        // make group set
        unordered_map<int, set<int>> gs; // group set
        for (int i = 1; i <= c; ++i) {
            gs[g[i]].insert(i);
        }


        vector<int> ans;
        for (auto& it : queries) {
            if (it[0] == 1) {  // operation 1
                if (gs[g[it[1]]].size() == 0) {
                    ans.push_back(-1);
                }
                else if (gs[g[it[1]]].find(it[1]) != gs[g[it[1]]].end()) {
                    ans.push_back(it[1]);
                }
                else {  // not exist
                    ans.push_back(*gs[g[it[1]]].begin());
                }
            }
            else { // operation 2
                gs[g[it[1]]].erase(it[1]);
            }
        }

        return ans;

    }
};


// memory limit 
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {

        vector<int> g(c + 1, 0);

        // build tree
        unordered_map<int, set<int>> em;
        for (auto& it : connections) {
            em[it[0]].insert(it[1]);
            em[it[1]].insert(it[0]);
        }

        int group = 0;
        for (int i = 1; i <= c; ++i) {
            if (g[i] == 0) {
                group++;
                g[i] = group;

                vector<int> v(c + 1, 0);
                queue<int> q;
                q.push(i);
                int cnt = 0;
                while (!q.empty()) {
                    int c = q.front();
                    q.pop();

                    v[c] = 1;

                    // check em[c] exist
                    if (em[c].size() > 0) {
                        g[c] = group;
                    }
                    else {
                        g[c] = 0;
                    }
                    
                    for (auto& it : em[c]) {
                        if (v[it] == 0) {
                            q.push(it);
                            v[it] = 1;
                        }
                    }
                }


            }
        }

        // make group set
        em.clear();
        for (int i = 1; i <= c; ++i) {
            if(g[i] > 0) em[g[i]].insert(i);
        }


        vector<int> ans;
        for (auto& it : queries) {
            if (it[0] == 1) {  // operation 1
                if (g[it[1]] == -1) {
                    ans.push_back(-1);
                }
                else if (g[it[1]] == 0) {
                    ans.push_back(it[1]);


                }
                else {

                    if (em[g[it[1]]].size() == 0) {
                        ans.push_back(-1);
                    }
                    else if (em[g[it[1]]].find(it[1]) != em[g[it[1]]].end()) {
                        ans.push_back(it[1]);
                    }
                    else {  // not exist
                        ans.push_back(*em[g[it[1]]].begin());
                    }
                }
            }
            else { // operation 2
                if (g[it[1]] == 0) {
                    g[it[1]] = -1;
                }
                else {
                    em[g[it[1]]].erase(it[1]);
                }
            }
        }

        return ans;

    }
};


class Solution {
public:
    unordered_map<int, set<int> > mp;
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, int id, vector<int>& ids) {
        visited[node] = 1;
        ids[node] = id;
        mp[id].insert(node);
        for (auto nodes : adj[node]) {
            if (!visited[nodes]) {
                dfs(nodes, adj, visited, id, ids);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> visited(c + 1, 0);

        vector<vector<int>> adj(c + 1);

        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        vector<int> ids(c + 1);


        for (int i = 1; i <= c; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, i, ids);
            }
        }

        // for(int i=1;i<=c;i++){
        //     cout<<ids[i]<<" ";
        // }
        // cout<<endl;

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 1) {


                int node = queries[i][1];

                int check_id = ids[node];
                if (mp[check_id].count(node)) {
                    ans.push_back(node);
                }
                else if (mp[check_id].size() != 0) {
                    ans.push_back(*(mp[check_id].begin()));
                }
                else ans.push_back(-1);
            }
            else {

                int node = queries[i][1];

                int check_id = ids[node];

                if (mp[check_id].count(node)) {
                    mp[check_id].erase(node);
                }
            }
        }

        return ans;

    }
};
int main() {
    char c;
    Solution sol;
    vector<vector<int>> connections = { {1, 2}, {2, 3}, {3, 4}, {4, 5} };
    vector<vector<int>> queries = { {1, 3}, {2, 1}, {1, 1}, {2, 2}, {1, 2} };
    vector<int> ans = sol.processQueries(5, connections, queries);

    for (auto& it : ans) {
        cout << it << " ";
    }


    cin >> c;
} 