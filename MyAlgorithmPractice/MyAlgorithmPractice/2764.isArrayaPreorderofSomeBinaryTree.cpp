// 맵으로 쉽게 풀림.. 
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
#include <cmath>

using namespace std;

class Solution {
public:
	bool isPreorder(vector<vector<int>>& nodes) {
		unordered_map<int, vector<int>> m;

		int pre = nodes[0][0];
		m[nodes[0][1]].push_back(nodes[0][0]);
		for (int i = 1; i < nodes.size(); ++i) {
			if (nodes[i][0] != pre + 1) return false;
			m[nodes[i][1]].push_back(nodes[i][0]);
			pre = nodes[i][0];
		}
		//for (auto it : nodes) {
		//	m[it[1]].push_back(it[0]);
		//}

		for (auto it : m) {
			if (it.second.size() > 2) return false;
			if (it.first != -1 && it.first + 1 != it.second[0]) return false;
		}
		return true;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> nodes = { {0, -1}, {1, 0}, {2, 0}, {3, 1}, {4, 1} };

	cout << sol.isPreorder(nodes);

	cin >> c;
}
