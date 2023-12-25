// timeout   => memoization   필요함  그럴려면  queue로 안되고 recursiver  하게 풀어야함
// 시간상  skip
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>

// find for vector

using namespace std;

class Solution {
public:
	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
		vector<vector<int>> parents(n, vector<int>());

		for (auto &it : edges) {
			parents[it[1]].push_back(it[0]);
		}

		// find all parents 
		for (int i = 0; i < n; ++i) {
			queue<int> q;
			for (int j = 0; j < parents[i].size(); ++j) {
				q.push(parents[i][j]);
				//ancester[i].push_back(parents[i][j]);
			}

			while (!q.empty()) {
				int t = q.front();
				q.pop();

				if (parents[t].size() != 0) {
					for (auto &it : parents[t]) {

						// do not visit again
						vector<int>::iterator jt = find(parents[i].begin(), parents[i].end(), it);
						//cout << parents[i].find(t);
						if (jt != parents[i].end()) continue;

						q.push(it);
						parents[i].push_back(it);
					}
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			set<int> ts;
			for (auto &it : parents[i]) ts.insert(it);
			parents[i].clear();
			for (auto &it : ts) parents[i].push_back(it);
			sort(parents[i].begin(), parents[i].end());
		}

		return parents;
	}
};

// out of memory
class _Solution {
public:
	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
		vector<vector<int>> parents(n, vector<int>());
		vector<vector<int>> ancester(n, vector<int>());

		for (auto &it : edges) {
			parents[it[1]].push_back(it[0]);
		}

		// find all parents 
		for (int i = 0; i < n; ++i) {
			queue<int> q;
			for (int j = 0; j < parents[i].size(); ++j) {
				q.push(parents[i][j]);
				ancester[i].push_back(parents[i][j]);
			}

			while (!q.empty()) {
				int t = q.front();
				q.pop();
				if (parents[t].size() != 0) {
					for (auto &it : parents[t]) {
						q.push(it);
						ancester[i].push_back(it);
					}
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			set<int> ts;
			for (auto &it : ancester[i]) ts.insert(it);
			ancester[i].clear();
			for (auto &it : ts) ancester[i].push_back(it);
			sort(ancester[i].begin(), ancester[i].end());
		}

		return ancester;
	}
};


int main() {
	char c;

	Solution sol;


	vector<vector<int>> edgeList = {{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6}};
	vector<vector<int>> ans = sol.getAncestors(8, edgeList);

	for (auto &it : ans) {
		for (auto &jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}

	cin >> c;

}