//  easy
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

using namespace std;

class Solution {
public:
	int traverse(vector<vector<int>>& matrix, vector<int> colAcc, int cl, int rl, int row_idx, int row_num) {
		int tmax1 = 0, tmax2 = 0; 

		if (row_idx >= rl) return 0;


		// not select this row
		tmax1 = traverse(matrix, colAcc, cl, rl, row_idx+1, row_num);

		// select this row
		for (int i = 0; i < cl; ++i) {
			colAcc[i] |= matrix[i][row_idx];
		}
		row_num--;
		if (row_num == 0) {
			for (int i = 0; i < cl; ++i) if (colAcc[i] == 0) tmax2++;
			return max(tmax1, tmax2);;
		}
		else {
			tmax2 = traverse(matrix, colAcc, cl, rl, row_idx+1, row_num);
		}

		return max(tmax1, tmax2);
	}


	int maximumRows(vector<vector<int>>& matrix, int numSelect) {
		int rl = matrix[0].size();
		int row_num = rl - numSelect;

		int cl = matrix.size();
		if (row_num == 0) return cl;

		vector<int> colAcc(cl, 0);

		return traverse(matrix, colAcc, cl, rl, 0, row_num);
	}
};



int main() {
	char c;

	Solution sol;
	
	vector<vector<int>> matrix = { {0, 0, 1}, {1, 0, 0}, {0, 0, 0} }; // {0, 0, 0}, { 1, 0, 1 }, { 0, 1, 1 }, { 0, 0, 1 }};

	cout << sol.maximumRows(matrix, 2);

	cin >> c;
}