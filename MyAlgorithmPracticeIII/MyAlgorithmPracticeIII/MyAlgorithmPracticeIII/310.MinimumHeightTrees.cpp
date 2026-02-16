// See answer : Great Idea... !!! 
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
#include <chrono>
#include <iterator>

using namespace std;


// leaf 에서 하나씩 파먹어 가면서 ... 

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 0)
            return {};
        if (n == 1)
            return { 0 };
        vector<int>res;
        vector<int>degrees(n, 0);
        vector<vector<int>>adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);//creating adjacent list
            adj[edges[i][1]].push_back(edges[i][0]);
            degrees[edges[i][1]]++;//updating how many edges each node has
            degrees[edges[i][0]]++;
        }
        queue<int>queue;
        for (int i = 0; i < n; i++)
        {
            if (degrees[i] == 1)//adding all the leave nodes
                queue.push(i);
        }
        while (!queue.empty())
        {
            res.clear();// clear vector before we start traversing level by level.
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                int cur = queue.front();
                queue.pop();
                res.push_back(cur);//adding nodes to vector.Goal is to get a vector of  just 1 or 2 nodes available.
                for (auto& neighbor : adj[cur])
                {
                    degrees[neighbor]--;//removing current leave nodes
                    if (degrees[neighbor] == 1)//adding current leave nodes
                        queue.push(neighbor);
                }
            }
        }
        return res;
    }
};




// 타임아웃 
class _Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> l;

        for (auto& it : edges) {
            l[it[0]].push_back(it[1]);
            l[it[1]].push_back(it[0]);
        }


        vector<int> ans;
        int mht_depth = INT_MAX;
        for (int i = 0; i < n; ++i) {
            vector<bool> v(n, false);

            int depth = 0;
            queue<int> q;
            q.push(i);
            v[i] = true;

            // if depth is longher than min depth -> go next 
            if (depth > mht_depth) continue;

            while (!q.empty()) {
                queue<int> tq;

                while (!q.empty()) {
                    int cnode = q.front();
                    q.pop();

                    
                    for (auto& it : l[cnode]) {
                        if (v[it] == false) {
                            tq.push(it);
                            v[it] = true;
                        }
                    }
                }

                depth++;
                q = tq;
            }

            if (depth < mht_depth) {
                ans.clear();
                ans.push_back(i);
                mht_depth = depth;
            }
            else if (depth == mht_depth) {
                ans.push_back(i);
            }

        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    //"baeyh";

    vector<int> ans = sol.findMinHeightTrees(4, edges);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
