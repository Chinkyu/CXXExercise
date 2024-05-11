// ¥‰∫√¿Ω : DP
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
	long long maxPoints(vector<vector<int>>& points) {
		vector<long long> res((int)points[0].size(), 0);
		for (auto i = 0; i < points.size(); i++) {
			for (auto j = 0; j < points[i].size(); j++) {
				res[j] += points[i][j]; // Here, res[j] is the total points we have if we pick the j-th number in the i-th row.
				if (j > 0) res[j] = max(res[j], res[j - 1] - 1); // Here, we prepare vector res for the next row's points
			}
			for (int j = points[i].size() - 2; j >= 0; j--)
				res[j] = max(res[j], res[j + 1] - 1); // Here, we are still preparing vector res for the next row's points
		}
		return *max_element(res.begin(), res.end());
	}
};

class _Solution {
public:
	long long maxPoints(vector<vector<int>>& points) {
		int lr = points.size();
		int lc = points[0].size();

		int prv = -1;
		long long ans = 0;
		for (int i = 0; i < lr; ++i) {
			int tmax = points[i][0];

			for (int j = 1; j < lc; ++j) {
				tmax = max(tmax, points[i][j]);
			}

			ans += tmax;
			if (prv != -1) ans -= abs(prv - tmax);

		}
		
		return ans;
	}
};


int main() {
	char c;
	Solution sol;

	vector<vector<int>> points = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};

	cout << sol.maxPoints(points);

	cin >> c;
}