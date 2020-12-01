#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	void removeOne(vector<vector<int>> &M, int x, int y) {
		int xl = M.size();
		int yl = M[0].size();
		stack<pair<int, int>> st;

		st.push(make_pair(x, y));

		 
		do {
			x = st.top().first;
			y = st.top().second;
			M[x][y] = 0;
			st.pop();
			// x search
			for (int i = -1; i <= 1; i += 2) {
				//if (0 < x + i && x + i < xl) 
				if (x + i < 0) {
					if (M[xl - 1][y] == 1) st.push(make_pair(xl - 1, y));
					continue;
				}
				if (xl <= x + i) {
					if (M[0][y] == 1) st.push(make_pair(0, y));
					continue;
				}
				{
					if (M[x + i][y] == 1) st.push(make_pair(x + i, y));
				}
			}

			// y search
			for (int i = -1; i <= 1; i += 2) {
				//if (0 < y + i && y + i < yl) \





				if (y + i < 0) {
					if (M[x][yl - 1] == 1) st.push(make_pair(x, yl-1));
					continue;
				}
				if (yl <= y + i) {
					if (M[x][0] == 1) st.push(make_pair(x, 0));
					continue;
				}
				{
					if (M[x][y + i] == 1) st.push(make_pair(x, y + i));
				}
			}
		} while (!st.empty());
	}

	int findCircleNum(vector<vector<int>> &M) {
		int xl = M.size();
		int yl = M[0].size();
		int num = 0;

		// find one
		for (int i = 0; i < xl; ++i) {
			for (int j = 0; j < yl; ++j) {
				if (M[i][j] == 1) {
					num++;
					removeOne(M, i, j);
				}
			}
		}
		return num;
	}

};

int main() {
	char c;
	Solution sol;
//	vector<vector<int>> m =
//	{ {1, 1, 0},
//	{1, 1, 0},
//	{0, 0, 1} };
	
	vector<vector<int>> m =
	  { {1, 0, 0, 1},
		{0, 1, 1, 0},
		{0, 1, 1, 1},
		{1, 0, 1, 1}};


	cout << sol.findCircleNum(m);


	cin >> c;
}