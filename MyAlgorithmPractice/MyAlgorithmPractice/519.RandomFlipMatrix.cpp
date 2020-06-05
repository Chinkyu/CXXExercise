#include <iostream>
#include <vector>
#include <ctime>


using namespace std;

class Solution {
public:
	vector<vector<int>> v;
	vector<int> rcount;
	int rcount_num = 0;
	int nr = 0, nc = 0;
	Solution(int n_rows, int n_cols) : v(n_rows, vector<int> (n_cols, 0)), rcount(n_rows, n_cols) {
		srand(time(NULL));
		rcount_num = n_rows;
		nr = n_rows;
		nc = n_cols;
	}

	vector<int> flip() {
		int r, c;
		vector<int> ans;
		
		r = rand() % rcount_num;

		int j = 0;
		for (int i = 0; i < nr; ++i) {
			if (rcount[i] != 0) {
				if (j == r) {
					r = i;
					break;
				}
				j++;
			}
		}

		c = rand() % rcount[r];

		j = 0;
		for (int i = 0; i < nc; ++i) {
			if (v[r][i] == 0) {
				if (j == c) {
					c = i;
					break;
				}
				j++;
			}
		}

		v[r][c] = 1;
		rcount[r]--;
		if (rcount[r] == 0) rcount_num--;
		ans.push_back(r);
		ans.push_back(c);
		cout << r << " " << c << endl;
		return ans;
	}

	void reset() {
		for (int i = 0; i < nr; ++i) {
			for (int j = 0; j < nc; ++j) {
				v[i][j] = 0;
			}
		}

		for (int i = 0; i < nr; ++i )  rcount[i] = 0;
		rcount_num = nr;

	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

int main() {
	char c;
	Solution sol(1, 2);

	vector<int> p = sol.flip();
	p = sol.flip();
//	p = sol.flip();
//	p = sol.flip();

	sol.reset();
	sol.flip();

	cout << p[0] << " " << p[1] << endl;

	cin >> c;
}