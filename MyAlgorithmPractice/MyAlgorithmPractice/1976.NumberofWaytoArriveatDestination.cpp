//  답봤음 : 다익 스트라...
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
	void dijkstra(int src, vector<int>&dp, vector<long long int>&distance, vector<pair<int, long long int>>adj[]) {
		distance[src] = 0;
		dp[src] = 1;
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>qu;
		qu.push({ 0, src });
		while (qu.size()) {
			pair<long long int, int>top = qu.top();
			qu.pop();
			int node = top.second;
			long long int distancesofar = top.first;
			for (auto child : adj[node]) {
				int childNode = child.first;
				long long int  addeddistance = child.second;
				if (distancesofar + addeddistance > distance[childNode])
					continue;
				else if (distancesofar + addeddistance == distance[childNode]) {
					// cout<<node<<" "<<childNode<<" "<<dp[node]<<" "<<dp[childNode]<<endl;
					dp[childNode] += dp[node];
					dp[childNode] %= (int)((int)1e9 + 7);
				}
				if (distancesofar + addeddistance < distance[childNode]) {
					//   cout<<"oo"<<node<<" "<<childNode<<" "<<dp[node]<<" "<<dp[childNode]<<endl;
					distance[childNode] = distancesofar + addeddistance;
					// cout<<node<<" "<<childNode<<" "<<distance[childNode]<<" "<<distancesofar<<" "<<addeddistance<<endl;
					qu.push({ distance[childNode], childNode });
					dp[childNode] = dp[node];
					dp[childNode] %= (int)((int)1e9 + 7);
				}
			}
		}
	}
	int countPaths(int n, vector<vector<int>>& roads) {
		// dp[node]=no of ways to reach node in mini time
		// answer=dp[n-1]
		// let say for any node its min time be dist[node]
		// dp[node]+=dp[parent];
		vector<int>dp(n, 0);
		vector<long long int>distance(n, 1e15);
		vector<pair<int, long long int>>adj[n];
		for (int i = 0; i < roads.size(); i++) {
			adj[roads[i][0]].push_back({ roads[i][1], 1LL * roads[i][2] });
			adj[roads[i][1]].push_back({ roads[i][0], 1LL * roads[i][2] });
		}
		dijkstra(0, dp, distance, adj);
		// for (int i = 0; i < n; i++) {
		//     cout << distance[i] << " ";
		// }
		// cout << endl;
		// for (int i = 0; i < n; i++) {
		//     cout << dp[i] << " ";
		// }
		// cout << endl;
		return dp[n - 1] % (int(1e9) + 7);
	}
};

class Pair {
	int node;
	long d;
	Pair() {

	}
	Pair(int node, long d) {
		this.node = node;
		this.d = d;
	}
}

int main() {
	char c;
	Solution sol;

	vector<int> nums1 = { 0, 1, 1 }; // { 1, 1, 0, 1 };
	vector<int> nums2 = { 1, 0, 1 };// { 0, 1, 1, 0 };

	cout << sol.widestPairOfIndices(nums1, nums2);

	cin >> c;
}