// 답봤고 :  time out 해결 위해서  bitmap을 사용해야함... 
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

class _Solution {
public:
	int numberOfPaths(int n, vector<vector<int>>& corridors) {
		unordered_map<int, vector<int>> m;
		set<set<int>> s;

		for (auto &it : corridors) {
			m[it[0]].push_back(it[1]);
			m[it[1]].push_back(it[0]);
		}

		for (auto &it : m) {
			vector<int> &lst = it.second;
			int l = lst.size();
			for (int i = 0; i < l - 1; ++i) {
				for (int j = i + 1; j < l; ++j) {
					if (find(m[lst[i]].begin(), m[lst[i]].end(), lst[j]) != m[lst[i]].end()) {
						s.insert(set<int>{it.first, lst[i], lst[j]});
					}
				}
			}

		}

		return s.size();
	}
};

// much slower
class __Solution {
public:
	int numberOfPaths(int n, vector<vector<int>>& corridors) {
		unordered_map<int, vector<int>> m;
		set<set<int>> s;
		set < set<int>> pair;

		for (auto &it : corridors) {
			m[it[0]].push_back(it[1]);
			m[it[1]].push_back(it[0]);

			pair.insert(set<int> {it[0], it[1]});
		}

		for (auto &it : m) {
			vector<int> &lst = it.second;
			int l = lst.size();
			for (int i = 0; i < l - 1; ++i) {
				for (int j = i + 1; j < l; ++j) {
//					if (find(m[lst[i]].begin(), m[lst[i]].end(), lst[j]) != m[lst[i]].end()) {
//						s.insert(set<int>{it.first, lst[i], lst[j]});
//					}

					if (pair.find(set<int>{lst[i], lst[j]}) != pair.end()) {
						s.insert(set<int>{it.first, lst[i], lst[j]});
					}
				}
			}

		}

		return s.size();
	}
};

class Solution {
public:
	int numberOfPaths(int n, vector<vector<int>>& es) {
		int ret = 0;
		vector<bitset<1005>> g(n);
		vector<vector<int>> adjcents(n);
		for (auto&& e : es) {
			const int u = e[0] - 1;
			const int v = e[1] - 1;
			g[u][v] = 1;
			g[v][u] = 1;
			adjcents[u].push_back(v);
			adjcents[v].push_back(u);
		}
		for (int i = 0; i < n; i++) {
			for (int j : adjcents[i]) {
				for (int k : adjcents[i]) {
					if (g[j][k]) {
						ret++;
					}
				}
			}
		}
		return ret / 6;
	}
};

int main() {
	char c;
	Solution sol;

	pair<int, int> p1, p2;


	vector<vector<int>> corridors = { {2, 3} }; // { {1, 2}, { 5, 2 }, { 4, 1 }, { 2, 4 }, { 3, 1 }, { 3, 4 }};
	cout << sol.numberOfPaths(3, corridors);

	cin >> c;
}