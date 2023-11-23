// 내가 짜서 타임아웃 나는데.. 답보고 조정함.. 
// 기존에  guard와  1을 같이 처리 하는 부분에서  timeout 난것 같음. 
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

// W : 2
// Guiard : 3
class Solution {
public:
	int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
		vector<vector<int>> map(m, vector<int>(n, 0));

		for (auto &it : walls) {
			map[it[0]][it[1]] = 2;
		}
		for (auto &it : guards) {
			map[it[0]][it[1]] = 3;
		}

		for (auto &it : guards) {
			// for direction 
			for (int r = it[0] - 1; r >= 0; --r) {
				//if (r != it[0] && map[r][it[1]] == 1) break;
				if (map[r][it[1]] == 2 || map[r][it[1]] == 3) break;
				map[r][it[1]] = 1;
			}
			for (int r = it[0] + 1; r < m; ++r) {
				//if (r != it[0] && map[r][it[1]] == 1) break;
				if (map[r][it[1]] == 2 || map[r][it[1]] == 3) break;
				map[r][it[1]] = 1;
			}
			for (int c = it[1] - 1; c >= 0; --c) {
				//if (c != it[1] && map[it[0]][c] == 1) break;
				if (map[it[0]][c] == 2 || map[it[0]][c] == 3) break;
				map[it[0]][c] = 1;

			}
			for (int c = it[1] + 1; c < n; ++c) {
				//if (c != it[1] && map[it[0]][c] == 1) break;
				if (map[it[0]][c] == 2 || map[it[0]][c] == 3) break;
				map[it[0]][c] = 1;
			}
		}

		// count zero
		int ans = 0;
		for (auto &it : map) {
			for (auto &jt : it) {
				if (jt == 0) ans++;
			}
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	//vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
	//vector<vector<int>> walls = {{0, 1}, {2, 2}, {1, 4}};

	vector<vector<int>> guards = {{0, 1}, {0, 2}, {0, 3}};
	vector<vector<int>> walls = {{0, 0}};


	cout << sol.countUnguarded(1, 100000, guards, walls);

	cin >> c;

}