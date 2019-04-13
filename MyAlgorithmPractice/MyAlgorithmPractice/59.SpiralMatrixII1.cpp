#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> mat(n, vector<int>(n, 0));
		int direction = 0;
		vector<pair<int, int>> move = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

		int x = 0, y = -1;
		for (int i = 1; i <= n * n; ++i) {
			int nx = x + move[direction].first;
			int ny = y + move[direction].second;

			if (nx >= n || ny >= n || nx < 0 || ny < 0 ||
				(nx < n && ny < n && nx >= 0 && ny >= 0 && mat[nx][ny] != 0)) {
				direction++;
				direction %= 4;
				nx = x + move[direction].first;
				ny = y + move[direction].second;
			}

			x = nx;
			y = ny;
			mat[nx][ny] = i;
		}
		return mat;
	}
};

int main() {
	Solution sol;
	char c;

	vector<vector<int>> mat = sol.generateMatrix(10);

	for (auto itr : mat) {
		for (auto jtr : itr) {
			cout << jtr << " ";
		}
		cout << endl;
	}

	cin >> c;
}