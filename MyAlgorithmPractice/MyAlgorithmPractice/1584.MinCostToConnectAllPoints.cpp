// 그냥 무식하게 풀면 Timeout (_Solution)
//  Kruskal or Prime 을써야함
// Refer : https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

// 아래는  prime 을 사용함... 기억도 안남... !!! 
// 일단 요거는 넘어가자.. @!!! 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <map>

using namespace std;

class Solution {
public:
	int minCostConnectPoints(vector<vector<int>>& ps) {
		int n = ps.size(), res = 0, i = 0, connected = 0;
		vector<bool> visited(n);
		priority_queue<pair<int, int>> pq;
		while (++connected < n) {
			visited[i] = true;
			for (int j = 0; j < n; ++j)
				if (!visited[j])
					pq.push({ -(abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1])), j });
			while (visited[pq.top().second])
				pq.pop();
			res -= pq.top().first;
			i = pq.top().second;
			pq.pop();
		}
		return res;
	}
};

class _Solution {
public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		int l = points.size();
		//vector<unordered_map<int, int>> dv(l, unordered_map<int, int>());
		map<vector<int>, int> distance;

		// get distanes and assign to map
		for (int i = 0; i < l-1; ++i) {
			for (int j = i+1; j < l; ++j) {
				if (i == j) continue;
				distance[{i, j}] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
				distance[{j, i}] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
			}
		}

		unordered_map<int, bool> in_list;
		unordered_map<int, bool> out_list;

		in_list[0] = true;
		for (int i = 1; i < l; ++i) {
			out_list[i] = true;
		}

		int ans = 0;
		while (out_list.size() != 0) {
			int min = INT_MAX;
			int min_idx = -1;
			for (auto it : in_list) {
				for (auto jt : out_list) {
					if (distance[{it.first, jt.first}] < min) {
						min = distance[{it.first, jt.first}];
						min_idx = jt.first;
					}
				}
			}

			in_list[min_idx] = true;
			out_list.erase(min_idx);

			ans += min;
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

//	vector<vector<int>> points = { {3, 12}, {-2, 5}, {-4, 1} };
	vector<vector<int>> points = { {0, 0},{2, 2},{3, 10},{5, 2},{7, 0} };

	cout << sol.minCostConnectPoints(points);

	cin >> c;
}