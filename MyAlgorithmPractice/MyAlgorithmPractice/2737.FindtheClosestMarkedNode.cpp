// dijkstra 비슷하게 품..  디버깅 오래걸림. 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <cmath>

using namespace std;

class Solution {
public:
	int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
		unordered_map<int, int> vm, dm;
		unordered_map<int, vector<int>> gm;  // graph map, start edge - vector index

		for (int i = 0; i < n; ++i) {
			dm[i] = INT_MAX;
		}

		for (int i = 0; i < edges.size(); ++i) {
			gm[edges[i][0]].push_back(i);
		}


		queue<int> q;
		q.push(s);
		vm[s] = 1;
		dm[s] = 0;


		while (q.size() != 0) {
			int v = q.front();
			int dist = dm[v];
			q.pop();
			for (auto it : gm[v]) {
				int edge_idx = it;
				int nxt_idx = edges[edge_idx][1];
				if (vm[nxt_idx] == 1) {
					if (dm[nxt_idx] > (dist + edges[edge_idx][2])) {
						dm[nxt_idx] = dist + edges[edge_idx][2];
						q.push(nxt_idx);
					}
					// else nothing
				}
				else {
					vm[nxt_idx] = 1;
					dm[nxt_idx] = dist + edges[edge_idx][2];
					q.push(nxt_idx);
				}
			}
		}

		int mind = INT_MAX;
		for (auto it : marked) {
			mind = min(mind, dm[it]);
		}

		return (mind == INT_MAX)? -1 : mind;
	}
};

int main() {
	char c;

	Solution sol;

	//vector<vector<int>> edges = { {0, 1, 2}, {1, 2,3}, {2, 3, 2},{0, 3,4 } };
	vector<vector<int>> edges = { {0, 1, 2},{0, 2, 4},{1, 3, 1},{2, 3, 3},{3, 4, 2} };
	vector<int> marked = { 0, 4 };
	cout << sol.minimumDistance(5, edges, 1, marked);
	//cout << sol.longestString(3, 25, 48);

	cin >> c;
}
