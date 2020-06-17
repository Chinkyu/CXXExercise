#include <iostream>
#include <vector>
#include <ctime>


using namespace std;

class _Solution {
public:
	vector<vector<int>> v;
	vector<int> rcount;
	int rcount_num = 0;
	int nr = 0, nc = 0;
	_Solution(int n_rows, int n_cols) : v(n_rows, vector<int> (n_cols, 0)), rcount(n_rows, n_cols) {
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

class __Solution {
public:
	int nr = 0, nc = 0;
	vector<vector<bool>> v;
	__Solution(int n_rows, int n_cols) : v(n_rows, vector<bool>(n_cols, false)){
		srand(time(NULL));
		nr = n_rows;
		nc = n_cols;
	}

	vector<int> flip() {
		int r, c;
		vector<int> ans;

		r = rand() % nr;
		c = rand() % nc;

		if (v[r][c] == true) {
			// find next;
			for (int i = 0; i < nr; ++i) {
				for (int j = 0; j < nc; ++j) {
					if (v[i][j] == false) {
						r = i;
						c = j;
						break;
					}
				}
			}
		}

		if (r >= nr) r = nr - 1;
		if (c >= nc) c = nc - 1;
		v[r][c] = true;

		ans.push_back(r);
		ans.push_back(c);
		cout << r << " " << c << endl;
		return ans;
	}

	void reset() {
		for (int i = 0; i < nr; ++i) {
			for (int j = 0; j < nc; ++j) {
				v[i][j] = false;

			}
		}
	}
};

// from discussion 
class Solution {
public:
	int mx = 0;
	int row = 0;
	int col = 0;
	unordered_set<int> v;
	Solution(int n_rows, int n_cols) {
		mx = n_rows * n_cols;
		row = n_rows;
		col = n_cols;
	}

	vector<int> flip() {
		if (v.size() == mx) return {};
		int r = rand() % mx;
		while (v.count(r)) {
			r = (++r) % mx;
		}
		v.insert(r);
		return { r / col, r % col };
	}

	void reset() {
		v = {};
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
	Solution sol(4, 17);

	vector<int> p = sol.flip();
	for (int i = 0; i < 100; i++) {
		p = sol.flip();
		//	p = sol.flip();
		//	p = sol.flip();
	}
	
	sol.reset();
	sol.flip();

	cout << p[0] << " " << p[1] << endl;

	cin >> c;
}