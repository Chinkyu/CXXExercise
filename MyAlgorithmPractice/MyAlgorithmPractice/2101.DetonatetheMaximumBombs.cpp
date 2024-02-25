// tricky
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
	int maximumDetonation(vector<vector<int>>& bombs) {
		int l = bombs.size();

		vector<vector<int>> range(l, vector<int>(0, 0));

		for (int i = 0; i < l; ++i) {
			int r = bombs[i][2];
			for (int j = 0; j < l; ++j) {
				if (i == j) continue;

				double d = sqrt(pow(bombs[i][0] - bombs[j][0], 2) + pow(bombs[i][1] - bombs[j][1], 2));
				if (d <= r) range[i].push_back(j);
			}
		}

		int tmax = 0;
		for (int i = 0; i < l; ++i) {
			queue<int> q;
			set<int> s;

			q.push(i);

			do {
				int t = q.front();
				q.pop();

				if (s.find(t) == s.end()) {
					s.insert(t);
					for (auto it : range[t]) q.push(it);
				}

			} while (!q.empty());

			tmax = max(tmax, (int)s.size());
		}

		return tmax;

	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>>bombs = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}}; // { {1, 1, 5}, { 10,10,5 } };//{{2, 1, 3}, {6, 1, 4}};

	cout << sol.maximumDetonation(bombs);

	cin >> c;
}