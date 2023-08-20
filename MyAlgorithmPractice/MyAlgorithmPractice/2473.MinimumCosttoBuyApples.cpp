// copy answer - Need to check later 
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

//  이익후 다익스트라
class Solution {
public:
	vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
		// add k by 1 in advance
		k++;

		// build final answer vector and graph
		// the total space complexity is O(n^2) due to the graph;
		vector<long long> ans(n, LLONG_MAX);
		vector<vector<pair<int, int>>> graph(n);
		for (auto r : roads) {
			graph[r[0] - 1].push_back({ r[1] - 1, r[2] });
			graph[r[1] - 1].push_back({ r[0] - 1, r[2] });
		}

		// build a min heap for bfs
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for (int i = 0; i < n; i++) {
			pq.push({ appleCost[i], i });
		}

		// the brief idea is to update final cost of every city from a cheaper city,
		//     since the only way to cost less is to buy cheaper-cost apple from other cities

		// by min heap, we can start from the city with lowest cost of apple to the highest
		// use bfs to visit other cities from current city
		// update the final answer of other cities
		//     if they can cost less by buying the apple from the current city
		// stop adding to the queue if we cannot update that city's cost

		// repeat min heap while loop for n times
		// inner bfs loop for O(n)
		// the total time complexity is O(n^2);

		while (!pq.empty()) {
			int start = pq.top().second;
			long long cost = pq.top().first;
			pq.pop();

			// if the final answer is already less than the local apple cost
			//     skip this city
			if (ans[start] < cost) continue;
			ans[start] = cost;

			// queue for bfs
			// PS: do not use visit vector here
			//     since a better answer might occur by a different path
			//     e.g. by order: a->b, a->c, then a->c->b->d would be ignored
			queue<pair<int, long long>> q;
			q.push({ start, cost });

			// inner-loop for O(n)
			while (!q.empty()) {
				int pos = q.front().first;
				long long sum = q.front().second;
				q.pop();

				// update every neighbor if we have lower cost
				for (auto p : graph[pos]) {
					long long next = sum + k * p.second;
					if (ans[p.first] > next) {
						ans[p.first] = next;
						q.push({ p.first, next });
					}
				}
			}
		}
		return ans;
	}
};


// none
class Solution {
public:

	void findMinRouteCost(int n, vector<vector<int>> &roads, vector<int> &cost, int st) {
		vector<bool> visit(n, false);
		vector<int> cost(n, INT_MAX);
		queue<int> q;

		q.push(st);
		cost[st] = 0;

		while (!q.empty()) {
			int t = q.front();
			q.pop();
			visit[t] = true;

			//queue<int> tq;
			for (auto it : roads) {
				if (it[0] == t && visit[it[1]] == false) {
					q.push(it[1]);
					cost[it[1]] = min(cost[it[1]], it[2] + cost[it[0]]);
				}
				if (it[1] == t && visit[it[0]] == false) {
					q.push(it[0]);
					cost[it[0]] = min(cost[it[0]], it[2] + cost[it[1]]);
				}
			}
		}





	}

	vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {

	}
};

int main() {
	char c;

	Solution sol;
	vector<vector<int>> roads = { {0, 1},{0, 2},{0, 3} };

	cout << sol.minimumFuelCost(roads, 5);

	cin >> c;
}