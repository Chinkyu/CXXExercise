#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	void dump(vector<vector<int>> v) {
		for (auto it : v) {
			for (auto jt : it) {
				cout << jt << " ";
			}
			cout << endl;
		}
	}

	void sub_cc_rotate(vector <vector<int>> &matrix, int sx, int sy, int n) {

		for (int i = 0; i < n-1; ++i) {
			int temp = matrix[sx + i][sy];
			matrix[sx+i][sy] = matrix[sx][sy + n -1 - i];
			matrix[sx][sy + n -1 - i] = matrix[sx + n - 1  - i][sy + n-1];
			matrix[sx + n -1- i][sy + n-1] = matrix[sx + n-1][sy + i];
			matrix[sx + n-1][sy + i] = temp;

			dump(matrix);
		}
	}

	void sub_cw_rotate(vector <vector<int>> &matrix, int sx, int sy, int n) {

		for (int i = 0; i < n - 1; ++i) {
			int temp = matrix[sx][sy+i];
			matrix[sx][sy+i] = matrix[sx+n-1-i][sy];
			matrix[sx + n - 1 - i][sy] = matrix[sx + n - 1][sy + n - 1-i];
			matrix[sx + n - 1][sy + n - 1 - i] = matrix[sx + i][sy + n - 1];
			matrix[sx + i][sy + n - 1] = temp;

//			dump(matrix);
		}
	}

	void rotate(vector<vector<int>>& matrix) {
		int size = matrix.size();

		for (int i = size; i > 1; i -= 2) {
			sub_cw_rotate(matrix, (size - i)/2, (size - i) / 2, i);
		}
	}
};




int main() {
	Solution sol;
	char c;

	//vector<vector<int>> v = {
	//{1, 2, 3},
	//{4, 5, 6}, 
	//{7, 8, 9}
	//};

	vector<vector<int>> v = {
		{15,13, 2, 5},
	{14, 3, 4, 1 },
	{12, 6, 8, 9
},
	{16, 7,10,11}
	};


	//sol.sub_cw_rotate(v, 0, 0, 3);
	sol.rotate(v);

	for (auto it : v) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}

	cin >> c;
}