#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		int count = 0, arrow = INT_MIN;
		sort(points.begin(), points.end(), mysort);
		for (int i = 0; i < points.size(); i++) {
			if (arrow != INT_MIN && points[i][0] <= arrow) { continue; } //former arrow shot points[i] 
			arrow = points[i][1]; // new arrow shot the end of points[i]
			count++;
		}
		return count;
	}
	static bool mysort(vector<int>& a, vector<int>& b) {
		return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
	}
};

class _Solution {
public:
	int fineMaxDupPoint(vector<vector<int>> & points) {
		vector<pair<int, int>> p;

		for (auto it : points) {

			if (it[0] == 0 && it[1] == 0) continue;

			p.push_back(pair<int, int>(it[0], +1));
			p.push_back(pair<int, int>(it[1], -1));
		}

		sort(p.begin(), p.end(), [](pair<int, int> l, pair<int, int> r) {
			if (l.first == r.first) return l.second > r.second; return l.first < r.first; });


		int layer = 0, maxLayer = 0;
		int maxPoint = 0;

		for (auto it : p) {
			if (it.second == 1) {
				layer++;
				if (maxLayer < layer) {
					maxLayer = layer;
					maxPoint = it.first;
				}
			}
			else if (it.second == -1) {
				layer--;
			} // it.second == 0  => ignore
		}
		return maxPoint;
	}

	int burstPoint(int x, vector<vector<int>> & points) {
		int c = 0;

		for (int i = 0; i < points.size(); ++i) {
			if (points[i][0] == 0 && points[i][1] == 0) continue;

			if (points[i][0] <= x && x <= points[i][1]) {
				points[i][0] = 0;
				points[i][1] = 0;
			}
			else {
				c++;
			}
		}
		return c;
	}

	int findMinArrowShots(vector<vector<int>>& points) {
		int cnt = 0, rem = 0;

		if (points.size() <= 0) return 0;

		do{
			int p = fineMaxDupPoint(points);
			rem = burstPoint(p, points);
			cnt++;
		} while (rem > 0);
		return cnt;
	}
};


int main() {
	char c;
	//vector<vector<int>> points = { {10, 16},{2, 8},{1, 6},{7, 12} };

	vector<vector<int>> points = { {9, 17},{4, 12},{4, 8},{4, 8},{7, 13},{3, 4},{7, 12},{9, 15} };

	Solution sol;

	cout << sol.findMinArrowShots(points);

	cin >> c;
}