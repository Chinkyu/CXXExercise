// ¥‰∫√¿Ω : diskstra and dp
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
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges) {
            adj[it[0]].push_back({ it[1], it[2] });
            adj[it[1]].push_back({ it[0], it[2] });
        }
        vector<int> dis(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, n });
        dis[n] = 0;
        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();
            for (auto [v, edgeWeight] : adj[node]) {
                if (dis[node] + edgeWeight < dis[v]) {
                    dis[v] = dis[node] + edgeWeight;
                    pq.push({ dis[v], v });
                }
            }
        }
        vector<int> dp(n + 1, -1);
        function<int(int)> dfs = [&](int node) -> int {
            if (node == 1) return 1;
            if (dp[node] != -1) return dp[node];
            int ways = 0;
            for (auto [v, wt] : adj[node]) {
                if (dis[node] < dis[v]) {
                    ways = (ways + dfs(v)) % 1000000007;
                }
            }
            return dp[node] = ways;
            };
        return dfs(n);
    }
};

int main() {
	Solution sol;
	char c;

	//vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	vector<int> nums = { 1,4, 2, 3 };

	vector<double> ans = sol.medianSlidingWindow(nums, 4);

	for (auto& it : ans) {
		cout << it << " ";
	}

	cin >> c;
}
