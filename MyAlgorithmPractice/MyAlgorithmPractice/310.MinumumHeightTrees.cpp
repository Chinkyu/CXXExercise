#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int maxdep = 0;

	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		int l = edges.size();
		vector<int> ans;

		if (l <= 0) {
			ans.push_back(0);
			return ans;
		}

		if (l == 1) {
			ans.push_back(edges[0][0]);
			ans.push_back(edges[0][1]);
			return ans;
		}

		vector<int> eCount(n, 0);
		vector<int> eCount_backup(n, 0);
		vector<unordered_set<int>> eList(n);
		for (int i = 0; i < l; ++i) {
			eCount[edges[i][0]]++;
			eCount[edges[i][1]]++;
			eList[edges[i][0]].insert(edges[i][1]);
			eList[edges[i][1]].insert(edges[i][0]);
		}

		int maxEdgeCount = 0;
		do {
			eCount_backup = eCount;
			for (int i = 0; i < n; ++i) {
				if (eCount_backup[i] == 1) {
					eCount[i]--;
					for (auto it : eList[i]) {
						eCount[it]--;
						eList[it].erase(i);
					}
					eList[i].clear();
					eList[i].insert(-1);
				}
				
			}
			maxEdgeCount = 0;
			for (int i = 0; i < n; ++i) {
				if (maxEdgeCount < eCount[i]) maxEdgeCount = eCount[i];
			}
		} while(maxEdgeCount > 1);

		for (int i = 0; i < n; ++i) {
			if (eList[i].find(-1) == eList[i].end()) ans.push_back(i);
		}
		return ans;
	}
};


class __Solution {
public:
	int maxdep = 0;

	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		int l = edges.size();
		vector<int> ans;

		if (l <= 0) {
			ans.push_back(0);
			return ans;
		}

		vector<int> eCount(n, 0);
		vector<int> eCount_backup(n, 0);
		vector<unordered_set<int>> eList(n);
		for (int i = 0; i < l; ++i) {
			eCount[edges[i][0]]++;
			eCount[edges[i][1]]++;
			eList[edges[i][0]].insert(edges[i][1]);
			eList[edges[i][1]].insert(edges[i][0]);
		}

		int maxConnect = 0;
		for (int i = 0; i < n; ++i) {
			if (eCount[i] == 0 || eCount[i] == 1) continue;
			if (maxConnect == 0) {
				maxConnect = eCount[i];
				continue;
			}
			else {
				if (maxConnect != eCount[i]) {
					maxConnect = -1;
					break;
				}
			}
		}


		while(maxConnect == -1) {
			maxConnect = 0;
			eCount_backup = eCount;
			for (int i = 0; i < n; ++i) {
				if (eCount_backup[i] == 1) {
					eCount[i]--;
					for (auto it : eList[i]) {
						eCount[it]--;
						eList[it].erase(i);
					}
					eList[i].clear();
				}
			}

			maxConnect = 0;
			for (int i = 0; i < n; ++i) {
				if (eCount[i] == 0 || eCount[i] == 1) continue;
				if (maxConnect == 0) {
					maxConnect = eCount[i];
					continue;
				}
				else {
					if (maxConnect != eCount[i]) {
						maxConnect = -1;
						break;
					}
				}
			}
		};

		for (int i = 0; i < n; ++i) {
			if (maxConnect > 0) {
				if(eCount[i] != 0 && eCount[i] != 1) ans.push_back(i);
			}
			else {
				if(eCount[i] == 1) ans.push_back(i);
			}
		}
		return ans;
	}
};

class _Solution {
public:
	int maxdep = 0;
	void traverse(vector<vector<int>> & edges, vector<bool> &visit, int edge, int depth) {
		if (maxdep < depth) maxdep = depth;

		visit[edge] = true;
		for (int i = 0; i < edges.size(); ++i) {
			if (edges[i][0] == edge && visit[edges[i][1]] == false) {
				traverse( edges, visit, edges[i][1], depth + 1);
			}
			else if (edges[i][1] == edge && visit[edges[i][0]] == false) {
				traverse(edges, visit, edges[i][0], depth + 1);
			}
		}
	}


	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		int l = edges.size();
		vector<int> ans;

		if (l <= 0) {
			ans.push_back(0);
			return ans;
		}
		vector<int> maxTab(n, 0);
		vector<bool> visit(n, false);

		int min = n;
		for (int i = 0; i < n; ++i) {
			maxdep = 0;
			for (int j = 0; j < n; ++j) visit[j] = false;
			traverse(edges, visit, i, 0);
			maxTab[i] = maxdep;
			if (min > maxdep) min = maxdep;
		}

		for (int i = 0; i < n; ++i) {
			if (maxTab[i] == min) ans.push_back(i);
		}
		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	//vector<vector<int>> edges = { {1, 0}, {1, 2}, {1,3} };
	//vector<int> ans = sol.findMinHeightTrees(4, edges);

	//vector<vector<int>> edges = { {0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4} };
	//vector<int> ans = sol.findMinHeightTrees(6, edges);

	//vector<vector<int>> edges = { {0, 1}, {0, 2}, {0, 3}, {3, 4}, {4, 5} };
	//vector<int> ans = sol.findMinHeightTrees(6, edges);

	//vector<vector<int>> edges = { {0, 1}, {1, 2}, {2, 3}, {0, 4}, {4, 5}, {4, 6}, {6, 7} };
	//vector<int> ans = sol.findMinHeightTrees(8, edges);

	vector<vector<int>> edges = { {0, 1}};
	vector<int> ans = sol.findMinHeightTrees(2, edges);

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}