//   ¥‰∫√¿Ω : BFS..?? :  
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
		vector<int>adj[patience.size()];

		for (auto it : edges) {
			adj[it[0]].push_back(it[1]);
			adj[it[1]].push_back(it[0]);
		}
		vector<int>vis(patience.size(), -1);
		patience[0] = 0;
		queue<pair<int, int>>q;
		q.push({ 0,0 });

		while (!q.empty()) {
			int node = q.front().first;
			int dis = q.front().second;
			q.pop();
			for (auto it : adj[node]) {
				if (vis[it] == -1) {
					vis[it] = dis + 1;
					q.push({ it,vis[it] });
				}
			}
		}
		int ans = 0;
		for (int i = 1; i < patience.size(); i++) {
			ans = max(ans, patience[i] * ((vis[i] * 2 - 1) / patience[i]) + vis[i] * 2 + 1);
		}
		return ans;
	}
};


int main() {
	char c;
	Solution sol;

	vector<int> nums = { 3, 1 };

	cout << sol.countMaxOrSubsets(nums);

	cin >> c;
}