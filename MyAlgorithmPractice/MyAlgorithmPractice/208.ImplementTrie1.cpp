#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		int size = prerequisites.size();
		queue<int> q;
		vector<int> in(size, 0);

		for (int i = 0; i < size; ++i) {
			for (auto it : prerequisites[i]) {
				in[it]++;
			}
		}

		for (int i = 0; i < size; ++i) {
			if (in[i] == 0) q.push(i);
		}

		while (q.size() > 0) {
			int next = q.front();
			q.pop();

			in[next] = -1;
			for (auto jt : prerequisites[next]) {
				in[jt]--;
				if (in[jt] == 0) q.push(jt);
			}
		}

		// check in
		for (auto it : in) {
			if (it >= 0) return false;
		}
		return true;

	}
};

int main() {
	Solution sol;
	char c;
	vector<vector<int>> dep = { {}, {0} };

	cout << sol.canFinish(2, dep);

	cin >> c;
}
