#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> ans;

		int sz = prerequisites.size();
		stack<int> q;
		vector<int> in(numCourses, 0);
		vector<vector<int>> vMap(numCourses);

		for (auto it : prerequisites) {
			in[it[1]]++;
			vMap[it[0]].push_back(it[1]);
		}

		for (int i = 0; i < numCourses; ++i) {
			if (in[i] == 0) q.push(i);
		}

		while (q.size() > 0) {
			int next = q.top();
			q.pop();

			in[next] = -1;
			ans.push_back(next);
			for (auto jt : vMap[next]) {
				in[jt]--;
				if (in[jt] == 0) q.push(jt);
			}
		}

		// check in
		for (auto it : in) {
			if (it >= 0) {
				ans.clear();
				break;
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main() {
	Solution sol;
	char c;
	//	vector<vector<int>> dep = { {1, 0} };
	vector<vector<int>> dep = { {1, 0}, {2, 0}, {3, 1}, {3, 2} };

	vector<int> a = sol.findOrder(4, dep);
	for (auto it : a) {
		cout << it << " ";
	}

	cin >> c;
}
