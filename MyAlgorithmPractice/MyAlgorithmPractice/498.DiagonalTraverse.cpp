#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> oneLine(vector<vector<int>> & m, int x, int y) {
		int lx = m.size();
		int ly = m[0].size();
		vector<int> ans;
		bool isEven = false;

		if (((x + y) % 2) == 0) isEven = true;

		do {
			ans.push_back(m[x][y]);
			x--;
			y++;
		} while (0 <= x && x < lx &&  0 <= y && y < ly);

		// even no trans
		// odd reverse
		if (isEven == false) {
			reverse(ans.begin(), ans.end());
		}

		return ans;
	}

	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		int lx = matrix.size();
		if (lx <= 0) return ans;
		int ly = matrix[0].size();

		int sx = 0, sy = 0;

		for (sx = 0; sx < lx; ++sx) {
			vector<int> t = oneLine(matrix, sx, sy);
			ans.insert(ans.end(), t.begin(), t.end());
		}
		sx = lx - 1;
		for (sy = 1; sy < ly; ++sy) {
			vector<int> t = oneLine(matrix, sx, sy);
			ans.insert(ans.end(), t.begin(), t.end());
		}
		return ans;
	}
};

int main() {
	char c;
	//vector<vector<int>> m = {
	//	 {1, 2, 3},
	//	 {4, 5, 6},
	//	 {7, 8, 9}
	//};

	vector<vector<int>> m =

		//{
		// {2, 3}
		//};
	{ {3}, {2} };

	Solution sol;

	vector<int> ans = sol.findDiagonalOrder(m);
	for (auto it : ans) {
		cout << it << " ";
	}
	cin >> c;
}