#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
	int countComponents(int n, vector<vector<int>>& edges) {

		vector<bool> e(n, false);

		// Make Map
		unordered_map<int, list<int>> m;

		for (auto it : edges) {
			//if (m.find(it[0]) == m.end()) { // not exist 
			m[it[0]].push_back(it[1]);
			m[it[1]].push_back(it[0]);
		}


		int cnt = 0;

		int i = 0;
		while (i < n) {

			if (e[i] == true) {
				i++;
				continue;
			}

			queue<int> q;
			q.push(i);


			do {
				int id = q.front();
				q.pop();

				if (e[id] == true) continue;

				e[id] = true;
				for (auto it : m[id]) {
					if (e[it] == false) q.push(it);
				}
			} while (!q.empty());

			cnt++;
		}

		return cnt;
	}
};

int main() {
	char c;
	Solution sol;

	vector<vector<int>> edges = { {0, 1},{1, 2},{3, 4} };
	int ans = sol.countComponents(5, edges);

	//	vector<vector<int>> edges = { {2, 3},{1, 2},{1, 3} };
	//	int ans = sol.countComponents(4, edges);

	cout << "test : " << ans << endl;

	cin >> c;
}