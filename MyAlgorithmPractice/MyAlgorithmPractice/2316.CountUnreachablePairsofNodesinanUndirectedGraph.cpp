//  타임 아웃때문에 시간 조금 걸림.. 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	long long countPairs(int n, vector<vector<int>>& edges) {
		vector<int> count(n, 0);
		unordered_map<int, set<int>> m;

		for (auto it : edges) {
			m[it[0]].insert(it[1]);
			m[it[1]].insert(it[0]);
		}

		long long ans = 0;
		unordered_map<int, set<int>> am;
		vector<bool> checked(n, false);
		vector<int> checked_num(n, 0);
		for (int i = 0; i < n; ++i) {
			if (checked[i] == true) continue;

			queue<int> q;
			vector<bool> isVisited(n, false);
			isVisited[i] = true;

			for (auto it : m[i]) {
				if (isVisited[it] == false) {
					q.push(it);
					am[i].insert(it);
				}
			}
			while (!q.empty()) {
				int t = q.front();
				q.pop();
				if (isVisited[t] == false) {
					isVisited[t] = true;

					for (auto it : m[t]) {
						if (isVisited[it] == false) {
							q.push(it);
							am[i].insert(it);
						}
					}
				}
			}
			
			checked_num[i] = am[i].size();
			for (auto it : am[i]) {
				checked[it] = true;
				checked_num[it] = checked_num[i];
			}
		}

		for (int i = 0; i < n; ++i) {
			ans += n - 1 - checked_num[i];
		}

		return ans / 2;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> edges = { {0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4} };

	cout << sol.countPairs(7, edges);
	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}