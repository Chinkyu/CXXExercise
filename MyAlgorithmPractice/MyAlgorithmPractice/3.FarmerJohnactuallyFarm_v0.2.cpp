#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;

	for (int tidx = 0; tidx < t; ++tidx) {
		int n; cin >> n;
		vector<int> init(n, 0), speed(n, 0), ranking(n, 0);
		vector<vector<int>> tr(n, vector<int>(4, 0));

		for (int i = 0; i < n; ++i) cin >> init[i];
		for (int i = 0; i < n; ++i) cin >> speed[i];
		for (int i = 0; i < n; ++i) cin >> ranking[i];

		for (int i = 0; i < n; ++i) {
			tr[i][0] = ranking[i];
			tr[i][1] = init[i];
			tr[i][2] = speed[i];
			tr[i][3] = init[i];  // height
		}

		sort(tr.begin(), tr.end(), [](vector<int> &ltr, vector<int> rtr) {
			return ltr[0] < rtr[0];
		});

		vector<int> gap(n, 0);
		int itr = 0;
		bool isAllPlus = true;
		for (int i = 1; i < n; ++i) {
			gap[i] = tr[i - 1][1] - tr[i][1];
			if (gap[i] <= 0) isAllPlus = false;
		}

		if (isAllPlus == true) {
			cout << 0 << endl;
			continue;
		}

		int iter = 0;
		do {
			isAllPlus = true;
			iter++;
			for (int i = 0; i < n; ++i) {
				tr[i][3] += tr[i][2];
				if (i >= 1) {  // check gap 

					if ((tr[i - 1][0] == tr[i][0] && ((tr[i - 1][3] < tr[i][3]) && (tr[i - 1][2] <= tr[i][2]))) ||
						(tr[i - 1][0] < tr[i][0] && ((tr[i - 1][3] <= tr[i][3]) && (tr[i - 1][2] <= tr[i][2])))) {
						//return -1; // no solution
						iter = -1;

						isAllPlus = true;
						break;
					}

					gap[i] = tr[i - 1][3] - tr[i][3];
					if (gap[i] <= 0) isAllPlus = false;  // not equal
				}
			}
		} while (false == isAllPlus);

		cout << iter << endl;

	}
}

