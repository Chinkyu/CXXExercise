#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	void dump(vector<int> &line) {
		for (auto it : line) {
			cout << it << " ";
		}
		cout << endl;
	}


	void iteration(vector<bool> &used, vector<vector<int>> &ans, vector<int> &line, int idx, int n, int k) {

		if (idx == k) {
			ans.push_back(line);
			dump(line);
			return;
		}

		int st = 1;
		if (idx > 0) st = line[idx - 1];

		for (int i = st; i <= n; i++) {
			if (used[i] == false) {
				used[i] = true;
				line[idx] = i;
				iteration(used, ans, line, idx + 1, n, k);
				used[i] = false;
			}
		}

	}

	vector<vector<int>> combine(int n, int k) {
		vector<bool> used(n+1, false);
		vector<int> line(k, 0);
		vector<vector<int>> ans;

		iteration(used, ans, line, 0, n, k);
		return ans;
	}
};

int main() {
	Solution sol;
	char c;

	sol.combine(4, 2);


	cin >> c;
}