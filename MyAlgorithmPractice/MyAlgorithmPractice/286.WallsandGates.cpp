// 너무 어렵게 생각해서...   Gate에서 하나하나씩 했는게 문제이고.
// 동시에 하며 visit 도 확인 할 필요 없는데...
// 
// 간단하게 해결 할 수 있는것을 좀 복잡하게 생각 하는 바람에.. Timeout이 났었음
// Solution을 참조해서 문제 해결함. 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

// BFS  modify  - do not need to maintain visit  - do not need trigger seperately
//              - do not need to maintain distance because fastone visit first.. 
class Solution {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		int h = rooms.size(), w = rooms[0].size();
		// find gate(0) and start calcurate distance with queue

		queue<pair<int, int>> q;   //  x, y, distance

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (rooms[i][j] == 0) q.push(pair<int, int>(i, j));
			}
		}

		while (!q.empty()) {
			int ci = q.front().first;  // x
			int cj = q.front().second;  // y
			int cd = rooms[ci][cj];  // d
			q.pop();

			// -1 , 0  // 0, -1	// 1, 0	// 0 , 1
			for (int i = ci - 1; i <= ci + 1; ++i) {
				for (int j = cj - 1; j <= cj + 1; ++j) {

					// exclude -1,-1  1,1   -1, 1   1, -1
					if ((i == ci - 1 && j == cj - 1) || (i == ci + 1 && j == cj + 1)
						|| (i == ci - 1 && j == cj + 1) || (i == ci + 1 && j == cj - 1)
						) continue;
					// check boundary
					if ((0 <= i && i < h) && (0 <= j && j < w)) {
						// check i, j
						if (rooms[i][j] == 0) continue;  // gate
						if (rooms[i][j] == -1) continue;  // wall
						// if visited 
						if (rooms[i][j] != 2147483647) continue;  // already visited

						rooms[i][j] = cd + 1;
						q.push(pair<int, int>(i, j));
					}
				}
			}
		}
	}
};


// DFS
class __Solution {
public:
	void measureDistance(vector<vector<int>>& rooms, vector<vector<bool>> &v, int si, int sj, int sd) {
		int h = rooms.size(), w = rooms[0].size();
		queue<vector<int>> q;   //  x, y, distance
		//vector<vector<bool>> v(h, vector<bool>(w, false));

		//v[si][sj] = true;

		int ci = si, cj = sj, cd = sd;

		// -1 , 0  // 0, -1	// 1, 0	// 0 , 1
		for (int i = ci - 1; i <= ci + 1; ++i) {
			for (int j = cj - 1; j <= cj + 1; ++j) {
				
				// exclude -1,-1  1,1   -1, 1   1, -1
				if ((i == ci - 1 && j == cj - 1) || (i == ci + 1 && j == cj + 1)
					|| (i == ci - 1 && j == cj + 1) || (i == ci + 1 && j == cj - 1)
					) continue;
				
				// check boundary
				if ((0 <= i && i < h) && (0 <= j && j < w)) {
					// if visited 
					if (v[i][j] == true && rooms[i][j] < cd + 1) continue;

					// check i, j
					if (rooms[i][j] == 0) continue;  // gate
					if (rooms[i][j] == -1) continue;  // wall
					if (rooms[i][j] == 2147483647) {
						rooms[i][j] = cd + 1;
						v[i][j] = true;
						measureDistance(rooms, v, i, j, cd + 1);
					}
					else {
						if (rooms[i][j] > cd + 1) {
							rooms[i][j] = cd + 1;
							v[i][j] = true;
							measureDistance(rooms, v, i, j, cd + 1);
						}
					}
			
				}
			}
		}
	}


	void wallsAndGates(vector<vector<int>>& rooms) {
		int h = rooms.size(), w = rooms[0].size();
		// find gate(0) and start calcurate distance with queue

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				vector<vector<bool>> v(h, vector<bool>(w, false));
				if (rooms[i][j] == 0) measureDistance(rooms, v, i, j, 0);
			}
		}
	}
};



// BFS
class _Solution {
public:
	void measureDistance(vector<vector<int>>& rooms, int si, int sj) {
		int h = rooms.size(), w = rooms[0].size();
		queue<vector<int>> q;   //  x, y, distance
		vector<vector<bool>> v(h, vector<bool>(w, false));

		q.push({ si, sj, 0 });
		v[si][sj] = true;
		while (!q.empty()) {
			int ci = q.front()[0];  // x
			int cj = q.front()[1];  // y
			int cd = q.front()[2];  // d
			q.pop();

			// -1 , 0  // 0, -1	// 1, 0	// 0 , 1
			for (int i = ci - 1; i <= ci + 1; ++i) {
				for (int j = cj - 1; j <= cj + 1; ++j) {

					// exclude -1,-1  1,1   -1, 1   1, -1
					if ((i == ci - 1 && j == cj - 1) || (i == ci + 1 && j == cj + 1)
						|| (i == ci - 1 && j == cj + 1) || (i == ci + 1 && j == cj - 1)
						) continue;
					// check boundary
					if ((0 <= i && i < h) && (0 <= j && j < w)) {
						// if visited 
						if (v[i][j] == true) continue;

						// check i, j
						if (rooms[i][j] == 0) continue;  // gate
						if (rooms[i][j] == -1) continue;  // wall
						if (rooms[i][j] == 2147483647) {
							rooms[i][j] = cd + 1;
							q.push({ i, j, cd + 1 });
							v[i][j] = true;
						}
						else {
							if (rooms[i][j] > cd + 1) {
								rooms[i][j] = cd + 1;
								q.push({ i, j, cd + 1 });
								v[i][j] = true;
							}
						}
					}
				}
			}
		}
	}


	void wallsAndGates(vector<vector<int>>& rooms) {
		int h = rooms.size(), w = rooms[0].size();
		// find gate(0) and start calcurate distance with queue

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (rooms[i][j] == 0) measureDistance(rooms, i, j);
			}
		}
	}
};

int main() {
	char c;

	Solution sol;
	vector<vector<int>> r = {{2147483647, -1, 0, 2147483647}, {2147483647, 2147483647, 2147483647, -1}, {2147483647, -1, 2147483647, -1}, {0, -1, 2147483647, 2147483647}};

	sol.wallsAndGates(r);

	for (auto it : r) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}

	//	cout << "test : " << ans << endl;

	cin >> c;
}