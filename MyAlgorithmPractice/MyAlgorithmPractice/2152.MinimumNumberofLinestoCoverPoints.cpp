// ´äºÃ½¿
#include <iostream>
#include <vector>
#include <unordered_map>
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
	bool isOneLine(vector<vector<int>>& points, int state) {
		vector<int>tmp;
		for (int i = 0; i < points.size(); i++) {
			if ((state >> i) & 1)
				tmp.push_back(i);
		}
		if (tmp.size() <= 2)
			return 1;
		for (int i = 1; i < tmp.size() - 1; i++) {
			int a = tmp[i - 1];
			int b = tmp[i];
			int c = tmp[i + 1];
			if ((points[c][0] - points[b][0])*(points[b][1] - points[a][1]) ==
				(points[b][0] - points[a][0])*(points[c][1] - points[b][1]))
				continue;
			else
				return false;
		}
		return true;
	}
public:
	int minimumLines(vector<vector<int>>& points) {
		int n = points.size();
		vector<int>dp(1 << n, INT_MAX / 2);
		for (int state = 1; state < 1 << n; state++) {
			if (isOneLine(points, state))
				dp[state] = 1;
		}

		for (int state = 0; state < (1 << n); state++) {
			if (dp[state] == 1)
				continue;
			for (int subState = state; subState > 0; subState = (subState - 1)&state) {
				dp[state] = min(dp[state], dp[subState] + dp[state - subState]);
			}
		}
		return dp[(1 << n) - 1];
	}

};
class _Solution {
public:
	int minimumLines(vector<vector<int>>& points) {
		int l = points.size();

		if (l <= 2) return l;

		sort(points.begin(), points.end(), 
			[](vector<int> &l, vector<int> &r) {
				return l[0] < r[0];
			});

		vector<bool> remain(points.size(), true);
		int rCount = l;

		int lCount = 0;
		int st = 0;
		while (st < l) {
			unordered_map<float, list<int>> m;

			for (int i = st + 1; i < l; ++i) {
				if (remain[i] == false) continue;
				float degree = (float)(points[i][1] - points[st][1]) / (float)(points[i][0] - points[st][0]);
				m[degree].push_back(i);
			}

			bool isLineExist = false;
			for (auto &it : m) {
				if (it.second.size() > 1) {
					lCount++;
					isLineExist = true;
					for (auto &jt : it.second) {
						remain[jt] = false;
						rCount--;
					}
				}
			}

			if (isLineExist == true) {
				remain[st] = false;
				rCount--;
			}
			else {
				lCount++;
			}

			st++;
			while (st < l && remain[st] == false) st++;
		}
		
		return lCount;
	}
};

int main() {
	char c;

	Solution sol;

	//vector<vector<int>> points = {{0, 1}, {2, 3}, {4, 5}, {4, 3}};
	//vector<vector<int>> points = { {0, 2}, {-2, -2}, {1, 4} };
	vector<vector<int>> points = {{0, 0}, {-5, 0}, {4, -2}, {3, -2}, {4, 2}, {1, -2}, {-2, -1}, {5, 0}};

	cout << sol.minimumLines(points);

	cin >> c;
}