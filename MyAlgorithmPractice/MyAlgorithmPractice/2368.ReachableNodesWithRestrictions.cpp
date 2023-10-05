// simple 
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

using namespace std;

class Solution {
public:
	int traverse(int r, unordered_map<int, set<int>> &m, vector<int> &visited) {
		int sum = 1;
		if (visited[r] == 1) return 0;

		visited[r] = 1;
		for (auto it : m[r]) {
			if (visited[it] != 1) {
				sum += traverse(it, m, visited);

			}
		}
		return sum;
	}

	int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
		unordered_map<int, set<int>> m;
		set<int> rset;

		for (auto it : restricted) rset.insert(it);

		for (int i = 0; i < edges.size(); ++i) {
			if (rset.find(edges[i][0]) == rset.end() && rset.find(edges[i][1]) == rset.end()) {
				m[edges[i][0]].insert(edges[i][1]);
				m[edges[i][1]].insert(edges[i][0]);
			}
		}

		vector<int> visited(n, 0);
		return traverse(0, m, visited);
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> edges = { {0, 1}, {1, 2}, {3, 1}, {4, 0}, {0, 5}, {5, 6} };
	vector<int> restricted = { 4, 5 };
	cout << sol.reachableNodes(7, edges, restricted);

	cin >> c;

}