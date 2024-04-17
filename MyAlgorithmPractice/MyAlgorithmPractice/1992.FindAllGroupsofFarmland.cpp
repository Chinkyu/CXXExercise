// easy : 
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

	void makeZero(vector<vector<int>> &land, int si, int sj, int ei, int ej) {

		for (int i = si; i <= ei; ++i) {
			for (int j = sj; j <= ej; ++j) {
				land[i][j] = 0;
			}
		}
	}

	vector<vector<int>> findFarmland(vector<vector<int>>& land) {
		int m = land.size(), n = land[0].size();

		vector<vector<int>> ans;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (land[i][j] == 1) {
					pair<int, int> start = { i, j };

					int ti = i, tj = j;
					// move asap
					bool isMove = false;
					do {
						isMove = false;

						if (ti + 1 < m && land[ti + 1][tj] == 1) {
							ti++; 
							isMove = true;
						}

						if (tj + 1 < n && land[ti][tj + 1] == 1) {
							tj++; 
							isMove = true;
						}

					} while (isMove == true);

					ans.push_back({ start.first, start.second, ti, tj });
					makeZero(land, start.first, start.second, ti, tj);
				}
			}
		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<vector<int>> land = { {1, 1, 0, 0, 0, 1}, {1, 1, 0, 0, 0, 0}};// { {1, 0, 0}, { 0, 1, 1 }, { 0, 1, 1 }};

	vector<vector<int>> ans = sol.findFarmland(land);

	for (auto &it : ans) {
		for (auto &jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}

	cin >> c;
}