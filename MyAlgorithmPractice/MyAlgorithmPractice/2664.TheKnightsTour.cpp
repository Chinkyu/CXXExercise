//	모든 경우수 recursive .. 
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
	vector<vector<int>> ans;
	bool found = false;

	void traverse(vector<vector<int>> &map, int m, int n, int r, int c, int seq) {

		if (found == true) return;

		if (seq == m * n - 1) {
			ans = map;
			found = true;
		}

		// eight direction 
		for (int i : {-1, -2, 1, 2}) {
			for (int j : {-1, -2, 1, 2}) {
				if (abs(i) == abs(j)) continue;
				int y = r + i;
				int x = c + j;

				if( 0 <= y && y < m && 0 <= x && x < n) {
					if (map[y][x] == -1) {
						map[y][x] = seq + 1;
						traverse(map, m, n, y, x, seq + 1);
						map[y][x] = -1;
					}
				}
			}
		}

	}


	vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
		ans.clear();
		found = false;
		vector<vector<int>> map(m, vector<int>(n, -1));

		map[r][c] = 0;
		traverse(map, m, n, r, c, 0);
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> ans = sol.tourOfKnight(3, 4, 0, 0);

	for (auto it : ans) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}

	cin >> c;
}
