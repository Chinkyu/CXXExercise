// Accepted... 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>

using namespace std;


//  Stack으로 풀면 쉽게 풀리겠네...
class Solution {
public:

	queue<int> q;

	int minReorder(int n, vector<vector<int>>& connections) {
		unordered_map<int, set<int>> fgraph, bgraph, allgraph;
		vector<bool> isVisited(n, false);
		int ans = 0;

		for (auto it : connections) {
			//fgraph[it[0]].push_back(it[1]);
			//bgraph[it[1]].push_back(it[0]);

			//allgraph[it[0]].push_back(it[1]);
			//allgraph[it[1]].push_back(it[0]);

			fgraph[it[0]].insert(it[1]);
			bgraph[it[1]].insert(it[0]);

			allgraph[it[0]].insert(it[1]);
			allgraph[it[1]].insert(it[0]);

		}

		q.push(0);
		isVisited[0] = true;

		while (!q.empty()) {
			int ck_point = q.front();
			q.pop();

			for (auto it : allgraph[ck_point]) {
				if (isVisited[it]) continue;
				if (fgraph[ck_point].find(it) != fgraph[ck_point].end()) {
					ans++;
				}

				q.push(it);
				isVisited[it] = true;
			}
		}

		return ans;

	}
};


int main() {
	char c;
	Solution sol;

	vector<vector<int>> con = { {0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5} };

	cout << sol.minReorder(6, con);

	//	cout << "test : " << ans << endl;

	cin >> c;
}