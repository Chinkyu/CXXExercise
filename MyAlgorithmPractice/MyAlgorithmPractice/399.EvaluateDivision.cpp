#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
#include <vector>

using namespace std;

class edge {
public:
	bool isVisited = false;
	double weight = 0;
	edge(bool bV, double dW) {
		isVisited = bV;
		weight = dW;
	}
};

class Solution {
public:
	map<pair<string, string>, double> wm;
	unordered_map<string, list<string>> em;
	unordered_map<string, bool> vm;
	bool isFound = false;
	double weight = -1;

	void traverse(string sst, string est, double w) {
		if (em.find(sst) == em.end()) {
			isFound = true; weight = -1; return;
		}

		if (sst == est) {
			isFound = true;
			weight = w;
			return;
		}

		vm[sst] = true;

		for (auto it : em[sst]) {
			if (vm[it] != true) {
				traverse(it, est, w * wm[make_pair(sst, it)]);
				if (isFound == true) return;
			}
		}
	}

	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		int l = values.size();
		vector<double> ans;

		if (l <= 0) return ans;
		for (int i = 0; i < l; ++i) {
			wm[make_pair(equations[i][0], equations[i][1])] = values[i];
			em[equations[i][0]].push_back(equations[i][1]);
			wm[make_pair(equations[i][1], equations[i][0])] = 1/values[i];
			em[equations[i][1]].push_back(equations[i][0]);
			vm[equations[i][0]] = false;
			vm[equations[i][1]] = false;
		}

		for (int i = 0; i < queries.size(); ++i) {
			// set all visited false
			isFound = false;
			weight = -1;
			for (auto it : vm) {
				vm[it.first] = false;
			}
			traverse(queries[i][0], queries[i][1], 1);
			ans.push_back(weight);
		}
		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<vector<string>> equations = { {"a", "b"},{"b", "c"} };
	vector<double> values = { 2.0, 3.0 };
	vector<vector<string>> queries = { {"a", "c"},{"b", "a"},{"a", "e"},{"a", "a"},{"x", "x"} };
	//vector<vector<string>> queries = { {"a", "b"}, {"b", "a"}};

	vector<double> ans = sol.calcEquation(equations, values, queries);

	for (auto is : ans) {
		cout << is << " ";
	}

	cin >> c;
}