//  쉽게 되었음.. 
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

	void recurse(vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> path, int idx, int v) {
		int l = graph.size();

		if (v == l - 1) {
			ans.push_back(path);
			return;
		}

		for (auto it : graph[idx]) {
			path.push_back(it);
			recurse(graph, ans, path, it, it);
			path.erase(path.end() - 1);
		}
	}

	vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
		vector<vector<int>> ans;
		vector<int> path;

		path.push_back(0);
		recurse(graph, ans, path, 0, 0);
		return ans;
	}
};


int main() {
	char c;

	Solution sol;

	//vector<vector<int>> graph = { {1,2}, {3}, {3}, {} };
	vector<vector<int>> graph = { {4, 3, 1}, {3,2, 4}, {3}, {4}, {} };


	vector<vector<int>> ans =  sol.allPathSourceTarget(graph);
	for (auto it : ans) {
		for (auto jt : it) {
			cout << " " << jt;
		}
		cout << endl;
	}


	cin >> c;
}