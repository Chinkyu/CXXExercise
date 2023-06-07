// 처음짠게 타임아웃
// 따로빼서 소팅해서 다시 쓰기...
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
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		int yl = mat.size(), xl = mat[0].size();

		//int x = 0;
		for (int y = 0; y < yl - 1; ++y) {
			int xi = 0, yi = y;
			vector<int> n;
			do {
				n.push_back(mat[yi++][xi++]);
			} while (xi < xl && yi < yl);
			
			sort(n.begin(), n.end());
			xi = 0; yi = y;
			int i = 0;
			do {
				mat[yi++][xi++] = n[i++];
			} while (i < n.size());
		}


		//int y = 0;
		for (int x = 1; x < xl - 1; ++x) {
			int xi = x, yi = 0;
			vector<int> n;
			do {
				n.push_back(mat[yi++][xi++]);
			} while (xi < xl && yi < yl);

			sort(n.begin(), n.end());
			xi = x; yi = 0;
			int i = 0;
			do {
				mat[yi++][xi++] = n[i++];
			} while (i < n.size());
		}

		return mat;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> mat = { {3, 3, 1, 1},{2, 2, 1, 2},{1, 1, 1, 2} };

	vector<vector<int>> ans = sol.diagonalSort(mat);

	for (auto it : ans) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}

	cin >> c;
}