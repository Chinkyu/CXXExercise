// easy :  lattice point 의 의미가 .....  
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>

using namespace std;

class Solution {
public:
	double distance(int x1, int y1, int x2, int y2) {
		long long up = pow(x1 - x2, 2) + pow(y1 - y2, 2);
		return sqrt(up);
	}

	int countLatticePoints(vector<vector<int>>& circles) {
		set<pair<int, int>> s;

		for (auto &it : circles) {
			int x = it[0], y = it[1], r = it[2];
			for (int i = x - r; i <= x + r; ++i) {
				for (int j = y - r; j <= y + r; ++j) {
					double d = distance(x, y, i, j);
					if (d <= r) s.insert(make_pair(i, j));
				}
			}
		}

		return s.size();
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> circles = { {2, 2, 2}, {3, 4, 1} };

	cout << sol.countLatticePoints(circles);

	cin >> c;

}