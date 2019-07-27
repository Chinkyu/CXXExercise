#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size();
		
		if (m <= 0) return 0;
		int n = grid[0].size();
		stack<int> sx, sy;

		char cnt = '2'; int icnt = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				sx.empty();
				sy.empty();

				//cout << grid[i][j] << " ";
				if (grid[i][j] == '1') {
					// processing 
					sx.push(i);
					sy.push(j);
					while (sx.size() > 0) {
						int cx = sx.top(), cy = sy.top();
						sx.pop(); sy.pop();

						grid[cx][cy] = cnt;
						
						for (int dx = -1; dx <= 1; ++dx) {
							for (int dy = -1; dy <= 1; ++dy) {
								if ((dx != 0 && dy != 0)) continue;
								if ((cx + dx >= 0 && cx + dx < m) && (cy + dy >= 0 && cy + dy < n)) {
									if (grid[cx + dx][cy + dy] == '1') {
										sx.push(cx + dx);
										sy.push(cy + dy);
									}
								}

							}
						}
					}
					cnt++; icnt++;
				}
				
			}
			//cout << endl;
		}
		return icnt;
		
    }
};

int main() {
	Solution sol;
	char c;
//	vector<vector<char>> map =
//		{ {1, 1, 1, 1, 0},
//		  {1, 1, 0, 1, 0},
//		  {1, 1, 0, 0, 0},
//		  {0, 0, 0, 0, 1}};

//	vector<vector<char>> map = { 
//	{'1', '1', '0', '0', '0'}, 
//	{'1', '1', '0', '0', '0'}, 
//	{'0', '0', '1', '0', '0'}, 
//	{'0', '0', '0', '1', '1'} };

	vector<vector<char>> map =
	{ 
	{'0', '1', '0'}, 
	{'1', '0', '1'}, 
	{'0', '1', '0'} };

//	for (int i = 0; i < map.size(); ++i) {
//		for (int j = 0; j < map[0].size(); j++) {
//			map[i][j] += '0';
//		}
//	}


	cout << sol.numIslands(map);

	for (auto it: map) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}
	cin >> c;
}
